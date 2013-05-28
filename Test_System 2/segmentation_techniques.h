#ifndef SEGMENTATION_TECHNIQUES_H
#define SEGMENTATION_TECHNIQUES_H

#include <qdebug.h>

#include "histogram_segmentation.h"

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class Segmentation_techniques
{
public:
    Segmentation_techniques();
};


cv::Mat Global_Sobel(cv::Mat input_img,int kernel_size,int histogram_percentile, int dx,int dy,bool Otsu);
cv::Mat Local_Sobel(cv::Mat input_img,int sub_images,int kernel_size,int histogram_percentile, int dx,int dy,bool Otsu,double x_weight, double y_weight);

cv::Mat Global_Scharr(cv::Mat input_img,int histogram_percentile, bool dx_checked,bool dy_checked,bool Otsu);
cv::Mat Local_Scharr(cv::Mat input_img,int sub_images,int histogram_percentile, bool dx_checked,bool dy_checked,bool Otsu,double x_weight, double y_weight);

cv::Mat Global_Otsu(cv::Mat input_img);
cv::Mat Local_Otsu(cv::Mat input_img, int sub_images);
cv::Mat Local_Otsu_neighbourhood(int x, int y,int width, int height,cv::Mat image);

cv::Mat Naive_Thresholding(cv::Mat input_img,int threshold);
cv::Mat Adaptive_Thresholding(cv::Mat input_img,int kernel_size,int C,bool Gaussian);

cv::Mat Light_gradient_equalizer(cv::Mat input_img, bool col);


#endif // SEGMENTATION_TECHNIQUES_H
