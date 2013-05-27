#ifndef GROWTH_DETECTION_H
#define GROWTH_DETECTION_H

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class Growth_Detection
{
public:
    Growth_Detection();
};

double percentage_foreground(cv::Mat input_image);

double Growth_Detection_algo(double standard_percentage, cv::Mat input_image);



#endif // GROWTH_DETECTION_H
