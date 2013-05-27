#include "tweaking.h"

cv::Mat tweak_video_frame(cv::Mat input_image)
{
    //----------------------------------------------------------------------------------------------//
    //for vertical tear
    cv::Mat output_image,buffer_image;
    output_image.create(input_image.rows, input_image.cols-300,input_image.type());
    buffer_image = input_image(cv::Rect(50,0,output_image.cols,output_image.rows));
    buffer_image.copyTo(output_image);
    //----------------------------------------------------------------------------------------------//







    return output_image;
}
