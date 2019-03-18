#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

void detectAndDisplay(Mat& frame, CascadeClassifier& cascade, VideoWriter& video);

int main() {
    const String cascade_name("cascade2.xml");
    CascadeClassifier cascade;

    if (!cascade.load(cascade_name)) {
        cout << "Error loading face cascade\n";
        return -1;
    }

    VideoCapture capture;
    capture.open("http://50.73.9.194:80/mjpg/video.mjpg");
    VideoWriter video("output.mp4", VideoWriter::fourcc('M','P','4','V'), 6,
            Size((int)capture.get(cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH),
                    (int)capture.get(cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT)));
    if (!capture.isOpened()) {
        cout << "Error opening video capture";
        return -1;
    }
    Mat frame;
    while(capture.read(frame)) {
        if (frame.empty()) {
            cout << "No capture frame!\n";
            return -1;
        }
        detectAndDisplay(frame, cascade, video);
        if (waitKey(10) == 27)
            break;
    }
    capture.release();
    video.release();
    return 0;
}

void detectAndDisplay(Mat& frame, CascadeClassifier& cascade, VideoWriter& video) {
    Mat frame_gray;
    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);

    std::vector<Rect> faces;
    cascade.detectMultiScale(frame_gray, faces);
    for (auto& face : faces)
        rectangle(frame, face, Scalar(255, 255, 0), 2);
    imshow("Cascade", frame);
    video.write(frame);
}
