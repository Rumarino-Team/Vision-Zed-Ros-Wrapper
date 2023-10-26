#ifndef __AI_MODULE__
#define __AI_MODULE__
// #include <filesystem>
#include <experimental/filesystem>
// We have to include the Zed Camera
#include <sl/Camera.hpp>
#include <filesystem>
#include <iostream>


// This is the file from the Detector of Yolov7
#include "yolov7.h"


// This variable is used for storing the CustomDetectedObjects that
// is transfer to the zed.ingestinference(). This vector is updated
// every grab of the camera.
using CustomDetectedObjects = std::vector<sl::CustomBoxObjectData>;

namespace zed_nodelets{
class AI {
    private:
        yolov7* Yolov7;


public:
    AI(std::string input_yaml);
    std::vector<sl::CustomBoxObjectData> detect_objects(std::vector<cv::Mat> &frames); //Corrected the return type
    std::vector<sl::CustomBoxObjectData> detect(sl::Mat &image);



};

}
#endif