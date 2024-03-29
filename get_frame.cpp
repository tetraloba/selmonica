#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

int main(){
    const string V_PATH = "rtsp://2909:4228@192.168.0.151/live";

    cv::VideoCapture cap(V_PATH);
    if (!cap.isOpened()) {
        cerr << "ERROR. Video Stream CAN'T BE OPEN" << endl;
        return 1;
    }

    cv::Mat frame;
    cap >> frame;
    if (frame.empty()) {
        cerr << "No frame can read." << endl;
        return 1;
    }

    cv::imwrite("frame.jpg", frame);
    return 0;
}
