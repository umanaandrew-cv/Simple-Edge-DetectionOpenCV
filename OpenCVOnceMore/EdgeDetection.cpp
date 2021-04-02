#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void main()
{
	//imports the images
	string path = "Resources/cards.jpg";
	Mat img = imread(path);
	Mat img2,imgLast;

	//converts the color to grayscale
	cvtColor(img, img2, COLOR_BGR2GRAY);
	
	//blurs out the image for better edge detection
	GaussianBlur(img2, img2, Size(7, 7), 75, 75);

	//gets the edges from the picture
	Canny(img2, img2, 25, 25);
	
	//dilates the Canny image to make edges more noticable 
	Mat kernel = getStructuringElement(MORPH_RECT, Size(2, 2));
	dilate(img2, img2, kernel);

	//printing out images
	imshow("First Image", img);
	imshow("Second Image", img2);
	waitKey(0);
}