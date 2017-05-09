#include "header/OpencvTest.h"

namespace test_proj {

ImageProcessing::ImageProcessing() {
    ts1 = 50;
    ts2 = 150;
    kernel_size = 3;
}

ImageProcessing::~ImageProcessing() {

}

void ImageProcessing::toCannyEdge(Mat& inputImg, Mat& outputImg) {

    Mat grayImg, detected_edges, dst;
    string type_input, type_output;

    /*type_input = type2str(inputImg.type());

    LOGI("intput type %s, output type %s", type_input.c_str());*/

    //cvtColor(inputImg, inputImg, CV_RGBA2BGR);

    /*type_input = type2str(inputImg.type());

    LOGI("convert intput type %s, output type %s", type_input.c_str());*/

    cvtColor(inputImg, grayImg, CV_RGBA2GRAY);

    GaussianBlur(grayImg, grayImg, Size(3,3), 0, 0);
    Canny(grayImg, detected_edges, ts1, ts2, 3);

    dst = Scalar::all(0);

    inputImg.copyTo( dst, detected_edges);

    //cvtColor(dst, outputImg, CV_GRAY2RGBA);

    outputImg = dst.clone();
}

string ImageProcessing::type2str(int type) {
    string r;

    uchar depth = type & CV_MAT_DEPTH_MASK;
    uchar chans = 1 + (type >> CV_CN_SHIFT);

    switch ( depth ) {
        case CV_8U:  r = "8U"; break;
        case CV_8S:  r = "8S"; break;
        case CV_16U: r = "16U"; break;
        case CV_16S: r = "16S"; break;
        case CV_32S: r = "32S"; break;
        case CV_32F: r = "32F"; break;
        case CV_64F: r = "64F"; break;
        default:     r = "User"; break;
    }

    r += "C";
    r += (chans+'0');

    return r;
}

} // namespace test_proj