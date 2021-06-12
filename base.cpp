#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;
Mat gray, gblur, canny, imge;
int RegOI(Mat imgroi);

int edgedetection(Mat imagefile)
{
	//Mat gray, gblur, canny;
	cvtColor(imagefile, gray, COLOR_BGR2GRAY);
	GaussianBlur(gray, gblur, Size(25, 25), 0, 0);
	Canny(gblur, canny, 40, 50);
	//imshow("Grayscale", gray);
	//imshow("Gaussian blur", gblur);
	//imshow("Canny", canny);
	//waitKey(100);
	RegOI(canny);
	return 0;
}

int RegOI(Mat imgri)
{
	Mat thrshld;
	imgri = imgri(Rect(0, 200, 900, 400));
	//imgri = imgri(Rect(0, 0, 900, 600));
	/*Rect(x,y,width,height) x-top horizontal, y - left vertical. Calculate remianing width and height as per x,y 
	values given wrt image resolution*/
	imshow("Region of interest", imgri);
	//threshold(imgri, thrshld, 150, 255, thresh_tozero); //applying threshold function to solidly map values above 150
	//imshow("thresholded image", thrshld);
	//in this module no big changes were observed. hence for optimizatioon commented for now.
	//waitkey(5000);
	vector<Vec4i> lines;
	HoughLinesP(imgri, lines, 1, CV_PI / 180, 100, 10, 300);
		// draw lines on the image
		for (size_t i = 0; i < lines.size(); i++) 
		{
				Vec4i l = lines[i];
				cout << l;
				line(imge, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255, 0, 0), 3, LINE_AA);
		}	
	imshow("drawn line", imge);
	waitKey(0);
	return 0;
}

int main()
{
	string path = "C:\\Users\\navee\\OneDrive\\Documents\\Naveen\\Lane.jpg";
	imge = imread(path);
	//imshow("Laneimage", imge);
	//waitKey(50);
	edgedetection(imge);
	return 0;
}