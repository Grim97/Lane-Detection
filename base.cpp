#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int RegOI(Mat imgroi);

int edgedetection(Mat imagefile)
{
	Mat gray, gblur, canny;
	cvtColor(imagefile, gray, COLOR_BGR2GRAY);
	GaussianBlur(gray, gblur, Size(11, 11), 0, 0);
	Canny(gblur, canny, 40, 50);
	//imshow("Grayscale", gray);
	//imshow("Gaussian blur", gblur);
	imshow("Canny", canny);
	waitKey(100);
	RegOI(canny);
	return 0;
}

int RegOI(Mat imgri)
{
	Mat thrshld;
	imgri = imgri(Rect(50, 50, 500, 500));
	imshow("Region of interest", imgri);
	//threshold(imgri, thrshld, 150, 255, THRESH_TOZERO); //applying threshold function to solidly map values above 150
	//imshow("Thresholded image", thrshld);
	//in this module no big changes were observed. Hence for optimizatioon commented for now.
	waitKey(0);
	return 0;
}

int main()
{
	string path = "C:\\Users\\navee\\OneDrive\\Documents\\Naveen\\Lane.jpg";
	Mat imge = imread(path);
	//imshow("Laneimage", imge);
	//waitKey(50);
	edgedetection(imge);
	return 0;
}