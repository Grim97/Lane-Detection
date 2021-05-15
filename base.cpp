#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int edgedetection(Mat imagefile)
{
	Mat gray, gblur, canny;
	cvtColor(imagefile, gray, COLOR_BGR2GRAY);
	GaussianBlur(gray, gblur, Size(11, 11), 0, 0);
	Canny(gblur, canny, 40, 50);
	imshow("Grayscale", gray);
	imshow("Gaussian blur", gblur);
	imshow("Canny", canny);
	waitKey(0);
	return 0;
}

int main()
{
	string path = "Github\\Lane\\Additional filesLane.jpg";
	Mat imge = imread(path);
	imshow("Laneimage", imge);
	//waitKey(50);
	edgedetection(imge);
	return 0;
}