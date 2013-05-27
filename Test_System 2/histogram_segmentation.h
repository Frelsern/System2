#ifndef HISTOGRAM_SEGMENTATION_H
#define HISTOGRAM_SEGMENTATION_H

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>


class Histogram_segmentation
{
public:
    Histogram_segmentation();
};

cv::Mat Histogram_seg(int desired_percentage,cv::Mat edge_img,cv::Mat original_img);
cv::Mat Histogram_seg(int desired_percentage,cv::Mat edge_img);

cv::Mat Otsu_on_Histo(cv::Mat histogram, cv::Mat image);




#endif // HISTOGRAM_SEGMENTATION_H
