#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

int main(int argc, char *argv[]){
    if (argc < 3) {
        cerr << "too few arguments" << endl;
        return 1;
    }
    const string V_PATH(argv[1]); // rtsp://2909:4228@192.168.0.151/live
    const string IMG_PATH(argv[2]); // 出力する画像のファイルパス

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

    cv::imwrite(IMG_PATH, frame);
    return 0;
}
