#ifndef HOLE_DETECTION_H
#define HOLE_DETECTION_H

#include <QList>
#include <QFile>

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

cv::Mat Hole_detection_algo(cv::Mat input_img);
cv::Vec6i Region_Growing(cv::Mat input_img,int x, int y, int color);


#endif // HOLE_DETECTION_H
