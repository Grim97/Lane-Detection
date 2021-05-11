#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	string path = "include your path here";
	Mat imge = imread(path);
	imshow("Laneimage", imge);
	waitKey(0);
	return 0;
}