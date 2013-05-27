#include "histogram_segmentation.h"

Histogram_segmentation::Histogram_segmentation()
{
}


cv::Mat Histogram_seg(int desired_percentage,cv::Mat edge_img,cv::Mat original_img)
{
    cv::Mat hist,output_img,original_image;
    original_img.copyTo(original_image);
    int histSize = 256;
    float ranges[] = {0,256};
    const float* histRange = {ranges};
    bool uniform = true;
    bool accumulate = false;

    cv::calcHist(&edge_img,1,0,cv::Mat(),hist,1,&histSize,&histRange,uniform,accumulate);

 /*   int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound((double)hist_w/histSize);
    cv::Mat histImage(hist_h,hist_w,CV_8U,cv::Scalar(0,0,0));

    //Normalizing the result to [0, histImage.rows]
    cv::normalize(hist,hist,0,histImage.rows,cv::NORM_MINMAX,-1,cv::Mat() );

    //draw for each channel
    for (int i = 1;i<histSize;i++)
    {
        cv::line(histImage,cv::Point(bin_w*(i-1), hist_h - cvRound(hist.at<float>(i-1)) ),
                 cv::Point( bin_w*(i), hist_h-cvRound(hist.at<float>(i)) ),
                 cv::Scalar(255,0,0),2,8,0 );
    }//kan droppe den koden her? trenger vel ikke å tege opp histogrammet, inegn som skal se det
    */


    //percentile2i from Digital image processing using matlab-----------------------//
    float sum = 0;
    float* data = hist.ptr<float>(0);
    for (int i = 0;i<256;i++)
    {
        sum = sum+data[i];
    }

    for(int i = 0;i<256;i++)
    {
        data[i] = data[i]/sum;
    }

     //cumulative sum
    for(int i = 1;i<256;i++ )
    {
        data[i] = data[i]+data[i-1];
    }

    //finding the index where the cummulative sum is equal to or greather than the changeable variabel
    float changeable_variable = (float)desired_percentage/100;
    float idx = 0;
    for (int i = 0;i<256;i++)
    {
        //if(hist.at<float>(i) >= changeable_variable)
        if(data[i] >= changeable_variable)
        {
            idx = i;
            break;
        }
    }

    //thresholding image
    int nl = edge_img.rows;
    int nc = edge_img.cols;
    if(edge_img.isContinuous())
    {
        nc = nc*nl;
        nl = 1; //1D array;
    }

    //loop exectued only once if the image is continious

    for(int j = 0; j<nl;j++)
    {
        uchar* edge_data = edge_img.ptr<uchar>(j);
        uchar* img_data = original_image.ptr<uchar>(j);

        for(int i = 0; i<nc;i++)
        {
            if(edge_data[i] <= idx)
            {
                img_data[i] = 0;//setting the value out of range
            }
        }
    }


    cv::Mat final_hist;
    cv::calcHist(&original_image,1,0,cv::Mat(),final_hist,1,&histSize,&histRange,uniform,accumulate);

    output_img = Otsu_on_Histo(final_hist, original_image);

    return output_img;//change after finisheed

}

cv::Mat Histogram_seg(int desired_percentage,cv::Mat edge_img)
{
    cv::Mat hist;
    int histSize = 256;
    float ranges[] = {0,256};
    const float* histRange = {ranges};
    bool uniform = true;
    bool accumulate = false;

    cv::calcHist(&edge_img,1,0,cv::Mat(),hist,1,&histSize,&histRange,uniform,accumulate);

    //percentile2i from Digital image processing using matlab-----------------------//
    float sum = 0;
    float* data = hist.ptr<float>(0);
    for (int i = 0;i<256;i++)
    {
        sum = sum+data[i];
    }

    for(int i = 0;i<256;i++)
    {
        data[i] = data[i]/sum;
    }

     //cumulative sum
    for(int i = 1;i<256;i++ )
    {
        data[i] = data[i]+data[i-1];
    }

    //finding the index where the cummulative sum is equal to or greather than the changeable variabel
    float changeable_variable = (float)desired_percentage/100;
    float idx = 0;
    for (int i = 0;i<256;i++)
    {
        //if(hist.at<float>(i) >= changeable_variable)
        if(data[i] >= changeable_variable)
        {
            idx = i;
            break;
        }
    }

    //-----------------------------------------------------------------------------//

    //thresholding image
    int nl = edge_img.rows;
    int nc = edge_img.cols;
    if(edge_img.isContinuous())
    {
        nc = nc*nl;
        nl = 1; //1D array;
    }

    //loop exectued only once if the image is continious
    for(int j = 0; j<nl;j++)
    {
        uchar* data = edge_img.ptr<uchar>(j);

        for(int i = 0; i<nc;i++)
        {
            if(data[i] > idx)
            {
                data[i] = 255;
            }
            else
            {
                data[i] = 0;
            }


        }
    }

    //-----------------------------------------------------------------------------//

    return edge_img;

}


cv::Mat Otsu_on_Histo(cv::Mat histogram, cv::Mat image)
{
    //this part of code is based on code found at
    //https://snipt.net/spechard/otsu-thresholding-with-opencv/
    //01.04.2013
    int hist_lvls = 256;
    float sum = 0;
    int total = 0;
    uchar* hist_data = histogram.ptr<uchar>(0);

    hist_data[0] = 0;//the histogram is dominated by 0s, they should however not count for the segmentation


    for(int i = 0;i<hist_lvls;i++)
    {
        sum = sum + i*hist_data[i];
        total = total+hist_data[i];//number of pixels
    }

    float sumB = 0;
    int wB = 0;
    int wF = 0;
    float varMax = 0;
    int threshold = 0;

    for(int i = 0;i<hist_lvls;i++)
    {
        wB += hist_data[i]; //weight background
        if(wB == 0)
        {
            continue;
        }

        wF = total-wB;
        if(wF == 0)
        {
            break;
        }

        sumB += (float)(i*hist_data[i]);

        float mB = sumB/wB;
        float mF = (sum-sumB)/wF;

        //calculating between class variance
        float varBetween = (float)wB*(float)wF*(mB-mF)*(mB-mF);
       // qDebug() << "between" <<varBetween;

        //Check if it is a new maximum
        if(varBetween>varMax)
        {
            varMax = varBetween;
            threshold = i;
        }

    }

    int nl = image.rows;
    int nc = image.cols;
    if(image.isContinuous())
    {
        nc = nc*nl;
        nl = 1; //1D array;
    }

    //loop exectued only once if the image is continious
    for(int j = 0; j<nl;j++)
    {
        uchar* img_data = image.ptr<uchar>(j);


        for(int i = 0; i<nc;i++)
        {
            if(img_data[i] > threshold)
            {
                img_data[i] = 255;//foreground
            }
            else
            {
                img_data[i]=0;//background
            }
        }
    }

    return image;

}
