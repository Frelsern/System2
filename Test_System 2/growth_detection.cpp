#include "growth_detection.h"
#include <QDebug>

Growth_Detection::Growth_Detection()
{
}

//Finds percentage of foreground pixels
double percentage_foreground(cv::Mat input_image)
{
    int nc = input_image.cols*input_image.rows;
    int foreground = 0;

    uchar* data = input_image.ptr<uchar>(0);
    for(int i = 0; i<nc;i++)
    {
        if(data[i] == 255)
        {
            //qDebug() << "passed if";
           foreground = foreground+1;
        }
    }
 //   qDebug() << "antall hvite pixler funnet" << foreground;
    double percentage = 100.0*foreground/nc;
    return percentage;
}

//for now it finds the percentage of growth on a scale from standard growth to 100% growth
double Growth_Detection_algo(double standard_percentage, cv::Mat input_image)
{
    double input_image_percentage = percentage_foreground(input_image);
    double diff = 0;

    if(input_image_percentage>standard_percentage)//dont accept negative growth
    {
       // qDebug() << "aksepterte bilde, positiv vekst";
        diff = input_image_percentage-standard_percentage;
        diff = diff*100/(100-standard_percentage);//rescaling difference to percentage of growth from standard growth to full growth

    }

    return diff;

}
