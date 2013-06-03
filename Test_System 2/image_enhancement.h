#ifndef IMAGE_ENHANCEMENT_H
#define IMAGE_ENHANCEMENT_H

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>


cv::Mat Light_gradient_equalizer(cv::Mat input_img);

cv::Mat Morpological_light_gradient_equalizer(cv::Mat input_image);

cv::Mat Morpological_contrast_enhancement(cv::Mat input_image);

#endif // IMAGE_ENHANCEMENT_H
