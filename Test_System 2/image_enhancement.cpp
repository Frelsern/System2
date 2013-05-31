#include "image_enhancement.h"

/*using sub_images of a twentieth of the original rowsize
equalize so that each sub image gets the same average intensity
as the first row.
Then does the same with sub_images a fourtieth of the original
colsize.
Needs an image size with rowsize that divides with 20 and colsize
that divides with 40
*/
cv::Mat Light_gradient_equalizer(cv::Mat input_image)
{
    cv::Mat equalized_image;
    input_image.copyTo(equalized_image);
    int colsize = equalized_image.cols;
    int rowsize = equalized_image.rows;

    int average_intensity = 0;
    int desired_intensity = 0;
    int pixel_batch = colsize*rowsize/20;
    uchar* data = equalized_image.ptr<uchar>(0);

    for(int i = 0; i< 20;i++)//vertical
    {
        double counter=0;

        for(int j = 0; j<(pixel_batch); j++)
        {
            counter = counter+data[j+i*pixel_batch];
        }
        if(i==0)
        {
            desired_intensity = counter/pixel_batch;
        }
        else
        {
            average_intensity = counter/pixel_batch;
            if(desired_intensity != average_intensity)
            {
                int difference = desired_intensity-average_intensity;

                for(int j = 0; j<(pixel_batch); j++)
                {
                    data[j+i*pixel_batch] = data[j+i*pixel_batch]+difference;
                }
            }
        }
    }

    for(int i = 0; i< 40;i++)//horizontal
    {
        cv::Mat sub_image,sub_image2;
        sub_image = equalized_image(cv::Rect(i*(colsize/40),0,colsize/40,rowsize));
        sub_image.copyTo(sub_image2);
        uchar* data = sub_image2.ptr<uchar>(0);
        double counter = 0;
        for(int j = 0; j<(sub_image2.cols*sub_image2.rows);j++)
        {
            counter = counter+data[j];
        }
        if(i==0)
        {
            desired_intensity = counter/(sub_image2.cols*sub_image2.rows);
        }
        else
        {
            average_intensity = counter/(sub_image2.cols*sub_image2.rows);

            if(desired_intensity != average_intensity)
            {
                int difference = desired_intensity-average_intensity;

                for(int j = 0; j<(sub_image2.cols*sub_image2.rows);j++)
                {
                    data[j] = data[j]+difference;
                }
                sub_image2.copyTo(sub_image);
            }
        }
    }

    return equalized_image;
}
