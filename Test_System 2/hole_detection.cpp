#include "hole_detection.h"
#include <QDebug>

cv::Mat Hole_detection_algo(cv::Mat input_img)
{
    cv::Mat output_img; //image with detected holes
    if((!input_img.empty())&& (input_img.channels()==1))
    {
        //lager en QList hvor størrelsen på regionene blir lagt inn
        //der kan man senere finne avvik fra normal region størrelse for å bestemme hull
        //enten lage ny liste per bilde eller global som husker gamle verdier, hmmmm.....
        QList<int> region_size_list;
        QList<cv::Vec6i> region_list;//[uppermost,furthest down,leftmost,rightmost,area,0]
        cv::Vec6i region;//kan bygge om til 4i, hvis nødvendig fordi topmost er den vi sender inn
        QList<int> printed_region_size_list;
        input_img.copyTo(output_img);

        int area;
        int color = 50;

        for(int j = 1;j<output_img.rows-1;j++)
        {
            uchar* data_row = output_img.ptr<uchar>(j);
            for(int i =1;i<output_img.cols-1;i++)
            {
                if(data_row[i] == 0)
                {
                    region = Region_Growing(output_img,j,i,color);
                    color = color + 50;
                    if(color>200)
                    {
                        color = 50;
                    }
                    area = region[4];

                    printed_region_size_list.append(area);
                    if(area>50)//to prevent small pixel areas to count
                    {
                        region_size_list.append(area);
                        region_list.append(region);
                    }
                }
            }
        }
        //temp part to print full region list
        if(printed_region_size_list.size()>0)
        {
            qSort(printed_region_size_list.begin(),printed_region_size_list.end());

            QString outputFilename = "region_sizes.txt";
            QFile outputFile(outputFilename);
            outputFile.open(QIODevice::WriteOnly);

            if(!outputFile.isOpen())
            {
                qDebug() << "klarte ikke å åpne";

            }
            else
            {
                QTextStream outStream(&outputFile);

                foreach(int size,printed_region_size_list)
                {
                    outStream << QString::number(size);
                    outStream << ",";
                }

                outputFile.close();


            }



        }




        //can instead make a sorting algorithm and not use an area list AND a coordinate list as now
        if(region_size_list.size()>0)
        {
            qSort(region_size_list.begin(),region_size_list.end());
            int median_area = region_size_list[(int)region_size_list.size()/2];

            //qDebug() << "lista har" << region_size_list.size()<<"elementer";
            //int antall=1;
            foreach(cv::Vec6i a ,region_list)
            {
                //region_list.removeFirst();//removes the item being examined
                //qDebug() << "antall removed" << antall;
                //antall+=1;

                //if the area in question is over three times the median area of the region_size_list then draw a circle around it
                if(a(4) >=  3*median_area)
                {
                   //drawing on image
                   cv::circle(output_img,cv::Point(a(2)+(a(3)-a(2))/2,a(0)+(a(1)-a(0))/2),(int)(a(1)-a(0))/2,0,4,8,0);
                }
            }
        }
    }



    return output_img;
}

//Grows region from a seed pixel, if the region contains pixels at the top AND bottom border
//or left AND right border the area is set to 0 to exclude the region from further processing
//This to eliminate false areas present during testing.
cv::Vec6i Region_Growing(cv::Mat input_img,int x, int y, int color)
{
    int area = 1;
    QList<cv::Vec2i> growing_list;
    growing_list.append(cv::Vec2i(x,y));
    cv::Vec6i returned_param;//[uppermost,furthest down,leftmost,rightmost,area,0]
    //returned_param = (x,x,y,y,area,0);
    returned_param[0] = x;
    returned_param[1] = x;
    returned_param[2] = y;
    returned_param[3] = y;
    returned_param[4] = area;
    returned_param[5] = 0;
    //growing_list.append(cv::Vec2i(5,6));
    input_img.at<uchar>(x,y) = color;
    bool change = true;


    //grow region and keep the pixels that are leftmost rightmost and furthest down, pixelnuber not coordinate
    while(change)
    {
        change = false;
        foreach(cv::Vec2i a ,growing_list)
        {
            growing_list.removeFirst();//removes the pixel being examined

            if((a(0)>0) && (a(1)>0) && (a(0)<(input_img.rows-1)) && (a(1)<(input_img.cols-1)) ) //dont use mask on border pixels.
            {
                uchar* previous_row = input_img.ptr<uchar>(a(0)-1);
                uchar* current_row = input_img.ptr<uchar>(a(0));
                uchar* next_row = input_img.ptr<uchar>(a(0)+1);
                if(previous_row[a(1)]==0)
                {
                    change = true;
                    growing_list.append(cv::Vec2i(a(0)-1,a(1)));
                    area = area+1;
                    previous_row[a(1)] = color;
                    if(a(0)-1< returned_param[0])//checking topmost, should never come into this one
                    {
                        returned_param[0]=a(0)-1;
                      // qDebug() << "kom inn i høyere rad enn vi begynnte med";
                    }
                }
                if(current_row[a(1)-1]==0)
                {
                    change = true;
                    growing_list.append(cv::Vec2i(a(0),a(1)-1));
                    area = area+1;
                    current_row[a(1)-1] = color;
                    if( (a(1)-1)<returned_param[2])//checking leftmost
                    {
                        returned_param[2]= a(1)-1;
                    }
                }
                if(current_row[a(1)+1]==0)
                {
                    change = true;
                    growing_list.append(cv::Vec2i(a(0),a(1)+1));
                    area = area+1;
                    current_row[a(1)+1] = color;
                    if( (a(1)+1)>returned_param[3])//checking rightmost
                    {
                        returned_param[3]= a(1)+1;
                    }
                }
                if(next_row[a(1)]==0)
                {
                    change = true;
                    growing_list.append(cv::Vec2i(a(0)+1,a(1)));
                    area = area+1;
                    next_row[a(1)] = color;
                    if(a(0)+1> returned_param[1])//checking lowest
                    {
                        returned_param[1]=a(0)+1;
                    }
                }
            }
        }
    }

    if(((returned_param[0]==0)&&(returned_param[1]==input_img.rows-1)) || ((returned_param[2]==0)&&(returned_param[3]==input_img.cols-1)))
    {
        returned_param[4] = 0;
       // qDebug() << "illegal area was: " << area << "coordinates " << returned_param[0] << returned_param[1] << returned_param[2] << returned_param[3];
    }
    else
    {
        returned_param[4]=area;
    }

    return returned_param;
}
