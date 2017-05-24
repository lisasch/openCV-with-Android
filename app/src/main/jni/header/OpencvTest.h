#ifndef OPENCV_TEST_OPENCVTEST_H_
#define OPENCV_TEST_OPENCVTEST_H_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <header/util.h>

using namespace std;
using namespace cv;

namespace test_proj {
class ImageProcessing {
	public:
		ImageProcessing();
		~ImageProcessing();

		void toCannyEdge(Mat& input, Mat& output);

		void savePath(char* str);
    	char* getsavePath();

	private:
		string type2str(int type);

		double ts1;
		double ts2;
		int kernel_size;

		char* saveFilePath;
};
} // namespace test_proj

#endif  // OPENCV_TEST_OPENCVTEST_H_
