#include "colorspaces.h"

colorspaces::colorspaces()
{
}


cv::Mat standard_x(cv::Mat input_image)
{

    cv::Mat XYZ,output_image;
    cv::cvtColor(input_image,XYZ,CV_RGB2XYZ);
    output_image.create(XYZ.size(), CV_8U);
    int num_pix = XYZ.rows*XYZ.cols;

    uchar* data = output_image.ptr<uchar>(0);
    uchar* old_data = XYZ.ptr<uchar>(0);
    for(int i = 0; i<num_pix;i++)
    {
        data[i] = 255*((double)old_data[3*i])/(old_data[3*i]+old_data[3*i+1]+old_data[3*i+2]) ;
    }

    return output_image;
}

cv::Mat standard_y(cv::Mat input_image)
{
    cv::Mat XYZ,output_image;
    cv::cvtColor(input_image,XYZ,CV_RGB2XYZ);
    output_image.create(XYZ.size(), CV_8U);
    int num_pix = XYZ.rows*XYZ.cols;

    uchar* data = output_image.ptr<uchar>(0);
    uchar* old_data = XYZ.ptr<uchar>(0);
    for(int i = 0; i<num_pix;i++)
    {
        data[i] = 255*((double)old_data[3*i+1])/(old_data[3*i]+old_data[3*i+1]+old_data[3*i+2]);
    }

    return output_image;
}

cv::Mat standard_Y(cv::Mat input_image)
{
    cv::Mat XYZ,output_image;
    cv::cvtColor(input_image,XYZ,CV_RGB2XYZ);
    output_image.create(XYZ.size(), CV_8U);
    int num_pix = XYZ.rows*XYZ.cols;

    uchar* data = output_image.ptr<uchar>(0);
    uchar* old_data = XYZ.ptr<uchar>(0);
    for(int i = 0; i<num_pix;i++)
    {
        data[i] = old_data[3*i+1];
    }

    return output_image;
}

cv::Mat custom_x(cv::Mat input_image)
{
    cv::Mat output_image,XYZ_image;
    XYZ_image.create(input_image.size(), input_image.type());
    output_image.create(input_image.size(), CV_8U);
    int num_pix = input_image.rows*input_image.cols;
    uchar* XYZ_data = XYZ_image.ptr<uchar>(0);
    uchar* old_data = input_image.ptr<uchar>(0);
    uchar* data = output_image.ptr<uchar>(0);
    for(int i = 0; i<num_pix;i++)
    {
        XYZ_data[3*i] = 0.607*old_data[3*i] + 0.174*old_data[3*i+1]+0.200*old_data[3*i+2];//X channel
        XYZ_data[3*i+1] = 0.299*old_data[3*i] + 0.587*old_data[3*i+1]+0.114*old_data[3*i+2];//Y channel
        XYZ_data[3*i+2] = 0.066*old_data[3*i+1]+1.111*old_data[3*i+2];//Z channel

        data[i] = 255*((double)XYZ_data[3*i])/(XYZ_data[3*i]+XYZ_data[3*i+1]+XYZ_data[3*i+2]) ;//x

    }
    return output_image;
}

cv::Mat custom_y(cv::Mat input_image)
{
    cv::Mat output_image,XYZ_image;
    XYZ_image.create(input_image.size(), input_image.type());
    output_image.create(input_image.size(), CV_8U);
    int num_pix = input_image.rows*input_image.cols;
    uchar* XYZ_data = XYZ_image.ptr<uchar>(0);
    uchar* old_data = input_image.ptr<uchar>(0);
    uchar* data = output_image.ptr<uchar>(0);
    for(int i = 0; i<num_pix;i++)
    {
        XYZ_data[3*i] = 0.607*old_data[3*i] + 0.174*old_data[3*i+1]+0.200*old_data[3*i+2];//X channel
        XYZ_data[3*i+1] = 0.299*old_data[3*i] + 0.587*old_data[3*i+1]+0.114*old_data[3*i+2];//Y channel
        XYZ_data[3*i+2] = 0.066*old_data[3*i+1]+1.111*old_data[3*i+2];//Z channel

        data[i] = 255*((double)XYZ_data[3*i+1])/(XYZ_data[3*i]+XYZ_data[3*i+1]+XYZ_data[3*i+2]) ;//y
    }
    return output_image;
}

cv::Mat custom_Y(cv::Mat input_image)
{
    cv::Mat output_image;
    output_image.create(input_image.size(), CV_8U);
    int num_pix = input_image.rows*input_image.cols;
    uchar* data = output_image.ptr<uchar>(0);
    uchar* old_data = input_image.ptr<uchar>(0);
    for(int i = 0; i<num_pix;i++)
    {
        data[i] = 0.299*old_data[3*i] + 0.587*old_data[3*i+1]+0.114*old_data[3*i+2];//Y channel
    }

   return output_image;
}


cv::Mat red_space(cv::Mat input_image)
{
    cv::Mat output_image;
    output_image.create(input_image.size(), CV_8U);
    int num_pix = input_image.rows*input_image.cols;

    uchar* data = output_image.ptr<uchar>(0);
    uchar* old_data = input_image.ptr<uchar>(0);
    for(int i = 0; i<num_pix;i++)
    {
        data[i] = old_data[3*i];
    }
    return output_image;
}
cv::Mat green_space(cv::Mat input_image)
{
    cv::Mat output_image;
    output_image.create(input_image.size(), CV_8U);
    int num_pix = input_image.rows*input_image.cols;

    uchar* data = output_image.ptr<uchar>(0);
    uchar* old_data = input_image.ptr<uchar>(0);
    for(int i = 0; i<num_pix;i++)
    {
        data[i] = old_data[3*i+1];
    }
    return output_image;
}

cv::Mat blue_space(cv::Mat input_image)
{
    cv::Mat output_image;
    output_image.create(input_image.size(), CV_8U);
    int num_pix = input_image.rows*input_image.cols;

    uchar* data = output_image.ptr<uchar>(0);
    uchar* old_data = input_image.ptr<uchar>(0);
    for(int i = 0; i<num_pix;i++)
    {
        data[i] = old_data[3*i+2];
    }
    return output_image;
}

cv::Mat L_space(cv::Mat input_image)
{
    cv::Mat output_image,lab_image;
    cv::cvtColor(input_image,lab_image,CV_RGB2Lab);
    output_image.create(input_image.size(), CV_8U);
    int num_pix = input_image.rows*input_image.cols;

    uchar* data = output_image.ptr<uchar>(0);
    uchar* old_data = lab_image.ptr<uchar>(0);
    for(int i = 0; i<num_pix;i++)
    {
        //data[i] = 2.55*old_data[3*i];//conversion to 0-255 scale
        data[i] = old_data[3*i];
    }
    return output_image;
}

cv::Mat a_space(cv::Mat input_image)
{
    cv::Mat output_image,lab_image;
    cv::cvtColor(input_image,lab_image,CV_RGB2Lab);
    output_image.create(input_image.size(), CV_8U);
    int num_pix = input_image.rows*input_image.cols;

    uchar* data = output_image.ptr<uchar>(0);
    uchar* old_data = lab_image.ptr<uchar>(0);
    for(int i = 0; i<num_pix;i++)
    {
        //data[i] = 1.0625*(120+old_data[3*i+1]);//conversion to 0-255 scale
        data[i] = old_data[3*i+1];
    }
    return output_image;
}

cv::Mat b_space(cv::Mat input_image)
{
    cv::Mat output_image,lab_image;
    cv::cvtColor(input_image,lab_image,CV_RGB2Lab);
    output_image.create(input_image.size(), CV_8U);
    int num_pix = input_image.rows*input_image.cols;

    uchar* data = output_image.ptr<uchar>(0);
    uchar* old_data = lab_image.ptr<uchar>(0);
    for(int i = 0; i<num_pix;i++)
    {
        //data[i] = 1.0625*(120+old_data[3*i+2]);//conversion to 0-255 scale
        data[i] = old_data[3*i+2];
    }
    return output_image;
}




