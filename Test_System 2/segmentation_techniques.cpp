#include "segmentation_techniques.h"
#include <QDebug>

Segmentation_techniques::Segmentation_techniques()
{
}


cv::Mat Global_Sobel(cv::Mat input_img,int kernel_size,int histogram_percentile, int dx,int dy,bool Otsu)
{
    cv::Mat output_img;
    if((input_img.channels()==1) && (!input_img.empty()) && (kernel_size > dx) && (kernel_size > dy) && (dx+dy>0))
    {


        cv::Mat edge_img;
        if((dx>0)&& (dy>0))
        {
            cv::Mat seg_dx,seg_dy;
            cv::Mat abs_seg_x,abs_seg_y;
            cv::Sobel(input_img,seg_dx,CV_32F,dx,0,kernel_size,1,0,cv::BORDER_REPLICATE);
            cv::Sobel(input_img,seg_dy,CV_32F,0,dy,kernel_size,1,0,cv::BORDER_REPLICATE);
            cv::convertScaleAbs(seg_dx,abs_seg_x);
            cv::convertScaleAbs(seg_dy,abs_seg_y);
            cv::addWeighted(abs_seg_x,1.0,abs_seg_y,0.5,0,edge_img);
        }
        else
        {
            cv::Sobel(input_img,edge_img,CV_32F,dx,dy,kernel_size,1,0,cv::BORDER_REPLICATE);
            edge_img.convertTo(edge_img,CV_8U);
        }

        if(Otsu)
        {
            output_img = Histogram_seg(histogram_percentile,edge_img,input_img);
        }
        else
        {
            output_img = Histogram_seg(histogram_percentile,edge_img);
        }
    }
    return output_img;
}

cv::Mat Local_Sobel(cv::Mat input_img,int sub_images,int kernel_size,int histogram_percentile, int dx, int dy,bool Otsu)
{
    cv::Mat output_img;
    if((input_img.channels()==1) && (!input_img.empty()) && (kernel_size > dx) && (kernel_size > dy) && (dx+dy>0))
    {
        //input_img.convertTo(input_img,CV_32F);
        int colsize = input_img.cols;
        int rowsize = input_img.rows;

        cv::Mat sub_image,sub_output_img,sub_image2, sub_image_dx,sub_image_dy,edge_img, abs_sub_dx,abs_sub_dy;
        sub_image.create(rowsize/sub_images,colsize/sub_images,CV_32F);
        sub_image2.create(rowsize/sub_images,colsize/sub_images,CV_32F);
        sub_image_dx.create(rowsize/sub_images,colsize/sub_images,CV_32F);
        sub_image_dy.create(rowsize/sub_images,colsize/sub_images,CV_32F);
        //edge_img = input_img.clone();
        edge_img.create(rowsize,colsize,CV_8U);
        input_img.convertTo(input_img,CV_32F);

        int c,d,e,f;
        for(int a = 0;a<sub_images;a++)
        {
            if(a == 0)
            {
                c=0;
                d = floor(1.0*rowsize/sub_images)-1;
            }else
            {
                c = d+1;
                d = d+floor(1.0*rowsize/sub_images);
            }

            for(int b = 0;b<sub_images;b++)
            {
                if(b == 0)
                {
                    e=0;
                    f = floor(1.0*colsize/sub_images)-1;
                }else
                {
                    e = f+1;
                    f = f+floor(1.0*colsize/sub_images);
                }

                sub_image = input_img(cv::Rect(e,c,sub_image.cols,sub_image.rows));
                sub_output_img = edge_img(cv::Rect(e,c,sub_image.cols,sub_image.rows));


                //cv::Sobel(sub_image2,sub_image,CV_32F,dx,dy,kernel_size,1,0,cv::BORDER_REPLICATE);

  //---------------------------------//


                if((dx>0)&&(dy>0))
                {
                   // cv::Mat seg_dx,seg_dy;

                    cv::Sobel(sub_image,sub_image_dx,CV_32F,dx,0,kernel_size,1,0,cv::BORDER_REPLICATE);
                    cv::Sobel(sub_image,sub_image_dy,CV_32F,0,dy,kernel_size,1,0,cv::BORDER_REPLICATE);

                    //cv::Sobel(input_img,seg_dx,CV_32F,dx,0,kernel_size,1,0,cv::BORDER_REPLICATE);
                    //cv::Sobel(input_img,seg_dy,CV_32F,0,dy,kernel_size,1,0,cv::BORDER_REPLICATE);
                    cv::convertScaleAbs(sub_image_dx,abs_sub_dx);
                    cv::convertScaleAbs(sub_image_dy,abs_sub_dy);
                    cv::addWeighted(abs_sub_dx,1.0,abs_sub_dy,0.5,0,sub_output_img);

                }
                else
                {
                    cv::Sobel(sub_image2,sub_output_img,CV_32F,dx,dy,kernel_size,1,0,cv::BORDER_REPLICATE);
                }


            }
        }

        if(((rowsize-1)-d)>0)//adds missing rows
         {
             sub_image.create((rowsize-1)-d,colsize/sub_images,CV_8U);
             //sub_image2.create((rowsize-1)-d,colsize/sub_images,CV_8U);
             c = d+1;
             for(int b = 0;b<sub_images;b++)
             {
                 if(b == 0)
                 {
                     e=0;
                     f = floor(1.0*colsize/sub_images)-1;
                 }else
                 {
                     e = f+1;
                     f = f+floor(1.0*colsize/sub_images);
                 }
                 sub_image = input_img(cv::Rect(e,c,sub_image.cols,sub_image.rows));
                 sub_output_img = edge_img(cv::Rect(e,c,sub_image.cols,sub_image.rows));

                 if((dx>0)&&(dy>0))
                 {

                     cv::Sobel(sub_image,sub_image_dx,CV_32F,dx,0,kernel_size,1,0,cv::BORDER_REPLICATE);
                     cv::Sobel(sub_image,sub_image_dy,CV_32F,0,dy,kernel_size,1,0,cv::BORDER_REPLICATE);
                     cv::convertScaleAbs(sub_image_dx,abs_sub_dx);
                     cv::convertScaleAbs(sub_image_dy,abs_sub_dy);
                     cv::addWeighted(abs_sub_dx,1.0,abs_sub_dy,0.5,0,sub_output_img);

                 }
                 else
                 {
                     cv::Sobel(sub_image2,sub_output_img,CV_32F,dx,dy,kernel_size,1,0,cv::BORDER_REPLICATE);
                 }

             }

         }
         if(((colsize-1)-d)>0)//adds missing coloumns
         {
             sub_image.create(rowsize/sub_images,(colsize-1)-f,CV_8U);

             e = f+1;
             for(int a = 0;a<sub_images;a++)
             {
                 if(a == 0)
                 {
                     c=0;
                     d = floor(1.0*rowsize/sub_images)-1;
                 }else
                 {
                     c = d+1;
                     d = d+floor(1.0*rowsize/sub_images);
                 }

                 sub_image = input_img(cv::Rect(e,c,sub_image.cols,sub_image.rows));
                 sub_output_img = edge_img(cv::Rect(e,c,sub_image.cols,sub_image.rows));

                 if((dx>0)&&(dy>0))
                 {

                     cv::Sobel(sub_image,sub_image_dx,CV_32F,dx,0,kernel_size,1,0,cv::BORDER_REPLICATE);
                     cv::Sobel(sub_image,sub_image_dy,CV_32F,0,dy,kernel_size,1,0,cv::BORDER_REPLICATE);
                     cv::convertScaleAbs(sub_image_dx,abs_sub_dx);
                     cv::convertScaleAbs(sub_image_dy,abs_sub_dy);
                     cv::addWeighted(abs_sub_dx,1.0,abs_sub_dy,0.5,0,sub_output_img);

                 }
                 else
                 {
                     cv::Sobel(sub_image2,sub_output_img,CV_32F,dx,dy,kernel_size,1,0,cv::BORDER_REPLICATE);
                 }
             }

         }
         if((((colsize-1)-d)>0) && (((rowsize-1)-d)>0))
         {
             sub_image.create((rowsize-1)-d,(colsize-1)-f,CV_8U);
             c = d+1;
             e = f+1;
             sub_image = input_img(cv::Rect(e,c,sub_image.cols,sub_image.rows));
             sub_output_img = edge_img(cv::Rect(e,c,sub_image.cols,sub_image.rows));

             if((dx>0)&&(dy>0))
             {

                 cv::Sobel(sub_image,sub_image_dx,CV_32F,dx,0,kernel_size,1,0,cv::BORDER_REPLICATE);
                 cv::Sobel(sub_image,sub_image_dy,CV_32F,0,dy,kernel_size,1,0,cv::BORDER_REPLICATE);
                 cv::convertScaleAbs(sub_image_dx,abs_sub_dx);
                 cv::convertScaleAbs(sub_image_dy,abs_sub_dy);
                 cv::addWeighted(abs_sub_dx,1.0,abs_sub_dy,0.5,0,sub_output_img);

             }
             else
             {
                 cv::Sobel(sub_image2,sub_output_img,CV_32F,dx,dy,kernel_size,1,0,cv::BORDER_REPLICATE);
             }
         }




        if(!((dx>0)&&(dy>0)))
        {
            edge_img.convertTo(edge_img,CV_8U);
        }


        //if(Otsu)
        //{
        //   output_img = Histogram_seg(histogram_percentile,edge_img,input_img);
        //}
        //else
       // {
            output_img = Histogram_seg(histogram_percentile,edge_img);
       // }
    }




    return output_img;
}

cv::Mat Global_Scharr(cv::Mat input_img,int histogram_percentile, bool dx_checked,bool dy_checked,bool Otsu)
{
    cv::Mat output_img;
    //Segmenting the image
    if((input_img.channels()==1) & (!input_img.empty()))
    {
        cv::Mat edge_img;
        if(dx_checked && dy_checked)
        {
            cv::Mat seg_dx,seg_dy;
            cv::Mat abs_seg_x,abs_seg_y;
            cv::Sobel(input_img,seg_dx,CV_32F,1,0,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
            cv::Sobel(input_img,seg_dy,CV_32F,0,1,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
            cv::convertScaleAbs(seg_dx,abs_seg_x);
            cv::convertScaleAbs(seg_dy,abs_seg_y);
            cv::addWeighted(abs_seg_x,1.0,abs_seg_y,0.5,0,edge_img);
        }
        else if(dx_checked)
        {
           cv::Sobel(input_img,edge_img,CV_32F,1,0,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
           edge_img.convertTo(edge_img,CV_8U);
        }
        else if(dy_checked)
        {
            cv::Sobel(input_img,edge_img,CV_32F,0,1,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
            edge_img.convertTo(edge_img,CV_8U);
        }

        //output_img = Histogram_seg(histogram_percentile,output_img,input_img);
        if(Otsu)
        {
            output_img = Histogram_seg(histogram_percentile,edge_img,input_img);
        }
        else
        {
            output_img = Histogram_seg(histogram_percentile,edge_img);
        }
    }


    return output_img;
}

cv::Mat Local_Scharr(cv::Mat input_img,int sub_images,int histogram_percentile, bool dx_checked,bool dy_checked,bool Otsu)
{
    cv::Mat output_img;
    if((input_img.channels()==1) && (!input_img.empty()))
    {
        int colsize = input_img.cols;
        int rowsize = input_img.rows;

        cv::Mat sub_image,sub_image2,edge_img;
        cv::Mat seg_dx,seg_dy;
        cv::Mat abs_seg_x,abs_seg_y;

         edge_img = input_img.clone();
         if(!(dx_checked & dy_checked))
         {
             edge_img.convertTo(edge_img,CV_32F);
             sub_image.create(rowsize/sub_images,colsize/sub_images,CV_32F);
             sub_image2.create(rowsize/sub_images,colsize/sub_images,CV_32F);
         }
         else
         {
             sub_image.create(rowsize/sub_images,colsize/sub_images,CV_8U);
             sub_image2.create(rowsize/sub_images,colsize/sub_images,CV_8U);
         }


         int c,d,e,f;
         for(int a = 0;a<sub_images;a++)
         {
             if(a == 0)
             {
                 c=0;
                 d = floor(1.0*rowsize/sub_images)-1;
             }else
             {
                 c = d+1;
                 d = d+floor(1.0*rowsize/sub_images);
             }

             for(int b = 0;b<sub_images;b++)
             {
                 if(b == 0)
                 {
                     e=0;
                     f = floor(1.0*colsize/sub_images)-1;
                 }else
                 {
                     e = f+1;
                     f = f+floor(1.0*colsize/sub_images);
                 }

                 sub_image = edge_img(cv::Rect(e,c,sub_image.cols,sub_image.rows));
                 sub_image.copyTo(sub_image2);

                 if(dx_checked && dy_checked)
                 {

                     cv::Sobel(sub_image2,seg_dx,CV_32F,1,0,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
                     cv::Sobel(sub_image2,seg_dy,CV_32F,0,1,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
                     cv::convertScaleAbs(seg_dx,abs_seg_x);
                     cv::convertScaleAbs(seg_dy,abs_seg_y);
                     cv::addWeighted(abs_seg_x,1.0,abs_seg_y,0.5,0,sub_image);//not perfect, can adjust dx and dy
                 }
                 else if(dx_checked)
                 {
                    cv::Sobel(sub_image2,sub_image,CV_32F,1,0,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
                 }
                 else if(dy_checked)
                 {
                     cv::Sobel(sub_image2,sub_image,CV_32F,0,1,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
                 }

             }
         }

         if(((rowsize-1)-d)>0)//adds missing rows
          {
              sub_image.create((rowsize-1)-d,colsize/sub_images,CV_8U);
              sub_image2.create((rowsize-1)-d,colsize/sub_images,CV_8U);
              c = d+1;
              for(int b = 0;b<sub_images;b++)
              {
                  if(b == 0)
                  {
                      e=0;
                      f = floor(1.0*colsize/sub_images)-1;
                  }else
                  {
                      e = f+1;
                      f = f+floor(1.0*colsize/sub_images);
                  }
                  sub_image = edge_img(cv::Rect(e,c,sub_image.cols,sub_image.rows));
                  sub_image.copyTo(sub_image2);

                  if(dx_checked && dy_checked)
                  {

                      cv::Sobel(sub_image2,seg_dx,CV_32F,1,0,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
                      cv::Sobel(sub_image2,seg_dy,CV_32F,0,1,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
                      cv::convertScaleAbs(seg_dx,abs_seg_x);
                      cv::convertScaleAbs(seg_dy,abs_seg_y);
                      cv::addWeighted(abs_seg_x,1.0,abs_seg_y,0.5,0,sub_image);//not perfect, can adjust dx and dy
                  }
                  else if(dx_checked)
                  {
                     cv::Sobel(sub_image2,sub_image,CV_32F,1,0,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
                  }
                  else if(dy_checked)
                  {
                      cv::Sobel(sub_image2,sub_image,CV_32F,0,1,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
                  }

              }

          }
          if(((colsize-1)-d)>0)//adds missing coloumns
          {
              sub_image.create(rowsize/sub_images,(colsize-1)-f,CV_8U);
              sub_image2.create(rowsize/sub_images,(colsize-1)-f,CV_8U);

              e = f+1;
              for(int a = 0;a<sub_images;a++)
              {
                  if(a == 0)
                  {
                      c=0;
                      d = floor(1.0*rowsize/sub_images)-1;
                  }else
                  {
                      c = d+1;
                      d = d+floor(1.0*rowsize/sub_images);
                  }

                  sub_image = edge_img(cv::Rect(e,c,sub_image.cols,sub_image.rows));
                  sub_image.copyTo(sub_image2);

                  if(dx_checked && dy_checked)
                  {

                      cv::Sobel(sub_image2,seg_dx,CV_32F,1,0,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
                      cv::Sobel(sub_image2,seg_dy,CV_32F,0,1,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
                      cv::convertScaleAbs(seg_dx,abs_seg_x);
                      cv::convertScaleAbs(seg_dy,abs_seg_y);
                      cv::addWeighted(abs_seg_x,1.0,abs_seg_y,0.5,0,sub_image);//not perfect, can adjust dx and dy
                  }
                  else if(dx_checked)
                  {
                     cv::Sobel(sub_image2,sub_image,CV_32F,1,0,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
                  }
                  else if(dy_checked)
                  {
                      cv::Sobel(sub_image2,sub_image,CV_32F,0,1,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
                  }
              }

          }
          if((((colsize-1)-d)>0) && (((rowsize-1)-d)>0))
          {
              sub_image.create((rowsize-1)-d,(colsize-1)-f,CV_8U);
              sub_image2.create((rowsize-1)-d,colsize-1-f,CV_8U);
              c = d+1;
              e = f+1;
              sub_image = edge_img(cv::Rect(e,c,sub_image.cols,sub_image.rows));
              sub_image.copyTo(sub_image2);

              if(dx_checked && dy_checked)
              {

                  cv::Sobel(sub_image2,seg_dx,CV_32F,1,0,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
                  cv::Sobel(sub_image2,seg_dy,CV_32F,0,1,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
                  cv::convertScaleAbs(seg_dx,abs_seg_x);
                  cv::convertScaleAbs(seg_dy,abs_seg_y);
                  cv::addWeighted(abs_seg_x,1.0,abs_seg_y,0.5,0,sub_image);//not perfect, can adjust dx and dy
              }
              else if(dx_checked)
              {
                 cv::Sobel(sub_image2,sub_image,CV_32F,1,0,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
              }
              else if(dy_checked)
              {
                  cv::Sobel(sub_image2,sub_image,CV_32F,0,1,CV_SCHARR,1,0,cv::BORDER_REPLICATE);
              }
          }


         if(!(dx_checked & dy_checked))
         {
             edge_img.convertTo(edge_img,CV_8U);
         }

         if(Otsu)
         {
             output_img = Histogram_seg(histogram_percentile,edge_img,input_img);
         }
         else
         {
             output_img = Histogram_seg(histogram_percentile,edge_img);
         }
    }


    return output_img;

}

cv::Mat Global_Otsu(cv::Mat input_img)
{
    cv::Mat output_img;
    if((input_img.channels()==1) && (!input_img.empty()))
    {
        output_img = input_img.clone();
        cv::threshold(input_img,output_img,0,255,cv::THRESH_BINARY | cv::THRESH_OTSU);
    }

    return output_img;
}


cv::Mat Local_Otsu(cv::Mat input_img, int sub_images)
{
    cv::Mat output_img;
    if((input_img.channels()==1) && (!input_img.empty()))
    {
        input_img.copyTo(output_img);
        int colsize = output_img.cols;
        int rowsize = output_img.rows;

        cv::Mat sub_image,sub_image2,sub_image3;
        sub_image.create(rowsize/sub_images,colsize/sub_images,CV_8U);
        sub_image2.create(rowsize/sub_images,colsize/sub_images,CV_8U);
        sub_image3.create(rowsize/sub_images,colsize/sub_images,CV_8U);
        int c,d,e,f;
        for(int a = 0;a<sub_images;a++)
        {
            if(a == 0)
            {
                c=0;
                d = floor(1.0*rowsize/sub_images)-1;
            }else
            {
                c = d+1;
                d = d+floor(1.0*rowsize/sub_images);
            }

            for(int b = 0;b<sub_images;b++)
            {
                if(b == 0)
                {
                    e=0;
                    f = floor(1.0*colsize/sub_images)-1;
                }else
                {
                    e = f+1;
                    f = f+floor(1.0*colsize/sub_images);
                }

                sub_image = output_img(cv::Rect(e,c,sub_image.cols,sub_image.rows));
                sub_image.copyTo(sub_image2);
                cv::threshold(sub_image2,sub_image,0,255,cv::THRESH_BINARY | cv::THRESH_OTSU);
                sub_image3 =  Local_Otsu_neighbourhood(e, c,floor(1.0*colsize/sub_images),  floor(1.0*rowsize/sub_images),output_img);
                sub_image3.copyTo(sub_image);


            }
        }
       if(((rowsize-1)-d)>0)//adds missing rows
        {
            sub_image.create((rowsize-1)-d,colsize/sub_images,CV_8U);
            sub_image2.create((rowsize-1)-d,colsize/sub_images,CV_8U);
            c = d+1;
            for(int b = 0;b<sub_images;b++)
            {
                if(b == 0)
                {
                    e=0;
                    f = floor(1.0*colsize/sub_images)-1;
                }else
                {
                    e = f+1;
                    f = f+floor(1.0*colsize/sub_images);
                }
                sub_image = output_img(cv::Rect(e,c,sub_image.cols,sub_image.rows));
                sub_image.copyTo(sub_image2);
                cv::threshold(sub_image2,sub_image,0,255,cv::THRESH_BINARY | cv::THRESH_OTSU);

            }

        }
        if(((colsize-1)-d)>0)//adds missing coloumns
        {
            sub_image.create(rowsize/sub_images,(colsize-1)-f,CV_8U);
            sub_image2.create(rowsize/sub_images,(colsize-1)-f,CV_8U);
            e = f+1;
            for(int a = 0;a<sub_images;a++)
            {
                if(a == 0)
                {
                    c=0;
                    d = floor(1.0*rowsize/sub_images)-1;
                }else
                {
                    c = d+1;
                    d = d+floor(1.0*rowsize/sub_images);
                }

                sub_image = output_img(cv::Rect(e,c,sub_image.cols,sub_image.rows));
                sub_image.copyTo(sub_image2);
                cv::threshold(sub_image2,sub_image,0,255,cv::THRESH_BINARY | cv::THRESH_OTSU);
            }

        }
        if((((colsize-1)-d)>0) && (((rowsize-1)-d)>0))
        {
            sub_image.create((rowsize-1)-d,(colsize-1)-f,CV_8U);
            sub_image2.create((rowsize-1)-d,(colsize-1)-f,CV_8U);
            c = d+1;
            e = f+1;
            sub_image = output_img(cv::Rect(e,c,sub_image.cols,sub_image.rows));
            sub_image.copyTo(sub_image2);
            cv::threshold(sub_image2,sub_image,0,255,cv::THRESH_BINARY | cv::THRESH_OTSU);
        }
    }
    return output_img;
}

cv::Mat Local_Otsu_neighbourhood(int x, int y,int width, int height,cv::Mat image)
{
    //qDebug() << x << y << width << height;
    cv::Mat last_sub,new_sub;
    if(y>0)
    {
        //topprad mot bunnrad
        last_sub = image(cv::Rect(x,y-1,width,1));
        new_sub = image(cv::Rect(x,y,width,height));
        int counter=0;
        uchar* new_sub_ptr = new_sub.ptr<uchar>(0);
        uchar* last_sub_ptr = last_sub.ptr<uchar>(0);
        for(int i = 0;i<width;i++)
        {
           // if(new_sub_ptr[i] != last_sub_ptr[i+width*(height-1)])//må faile her, se på bildene som er tatt, ikke <uchar>?
            if(new_sub_ptr[i] != last_sub_ptr[i])//må faile her, se på bildene som er tatt
            {
                counter +=1;
            }
            counter = width;
        }
        if(counter>(2*width/3))
        {
            //qDebug() << counter << width << x << y;
            //qDebug() << "kom hit" << x << y << width << height;
            imwrite(("new_sub.png"), new_sub );
            imwrite(("last_sub.png"),last_sub);
            uchar* sub_image_ptr = new_sub.ptr<uchar>(0);
            for(int i = 0;i<(width*height);i++)
            {
              //  qDebug() << new_sub_ptr[i];
                sub_image_ptr[i] = 255-sub_image_ptr[i];
            }

        }





        //venstre mot høyre
    }
    else
    {
        new_sub = new_sub = image(cv::Rect(x,y,width,height));
    }
    return new_sub;
}

cv::Mat Naive_Thresholding(cv::Mat input_img, int threshold)
{
    cv::Mat output_img;
    if((input_img.channels()==1) && (!input_img.empty()))
    {
        input_img.copyTo(output_img);
        int nl = output_img.rows;
        int nc = output_img.cols;
        if(output_img.isContinuous())
        {
            nc = nc*nl;
            nl = 1; //1D array;
        }

        //loop exectued only once if the image is continious
        for(int j = 0; j<nl;j++)
        {
            uchar* data = output_img.ptr<uchar>(j);
            for(int i = 0; i<nc;i++)
            {
                if(data[i]>=threshold)//bright pixels
                {
                    data[i]=255;
                }
                else
                {
                    data[i] = 0;
                }
            }
        }

    }

    return output_img;
}

cv::Mat Adaptive_Thresholding(cv::Mat input_img,int kernel_size, int C,bool Gaussian)
{
    cv::Mat output_img;
    if((input_img.channels()==1) && (!input_img.empty()))
    {
        input_img.copyTo(output_img);
        if(Gaussian)
        {
            cv::adaptiveThreshold(output_img,output_img,255.0,cv::ADAPTIVE_THRESH_GAUSSIAN_C,
                                  cv::THRESH_BINARY,kernel_size,C);
        }
        else
        {
            cv::adaptiveThreshold(output_img,output_img,255.0,cv::ADAPTIVE_THRESH_MEAN_C,
                                  cv::THRESH_BINARY,kernel_size,C);

        }

    }
    return output_img;
}
