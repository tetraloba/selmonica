#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

int main(int argc, char *argv[]){
    if (argc < 2) {
        cerr << "too few arguments" << endl;
        return 1;
    }
    const string IMG_PATH(argv[1]); // 出力する画像のファイルパス

    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "ERROR. device CAN'T BE OPEN" << endl;
        return 1;
    }
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1920);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 1080);

    cv::Mat frame;
    cap >> frame;
    if (frame.empty()) {
        cerr << "No frame can read." << endl;
        return 1;
    }

    cv::imwrite(IMG_PATH, frame);
    return 0;
}
