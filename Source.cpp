#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include "windows.h"
#include <iostream>
#include "math.h"
#include <iomanip>
#include <fstream>

using namespace cv;
using namespace std;

Mat	img, img2;
int r = 0, g = 0, b = 0;

void r_trackbar(int, void*) {
	int bb, gg, rr, media;
	for (int n = 0; n < img.rows; n++) {
		for (int m = 0; m < img.cols; m++) {
			bb = img2.at<cv::Vec3b>(n, m)[0];
			gg = img2.at<cv::Vec3b>(n, m)[1];
			rr = img2.at<cv::Vec3b>(n, m)[2];
			media = (bb + rr + gg) / 3;
			if (rr > media && rr > bb && rr > gg) {
				if (r < rr) {
					img.at<cv::Vec3b>(n, m)[0] = (int)media;
					img.at<cv::Vec3b>(n, m)[1] = (int)media;
					img.at<cv::Vec3b>(n, m)[2] = (int)media;
				}
				else {
					img.at<cv::Vec3b>(n, m)[0] = img2.at<cv::Vec3b>(n, m)[0];
					img.at<cv::Vec3b>(n, m)[1] = img2.at<cv::Vec3b>(n, m)[1];
					img.at<cv::Vec3b>(n, m)[2] = img2.at<cv::Vec3b>(n, m)[2];
				}
			}
		}
	}
	imshow("Imagem", img);
}

void g_trackbar(int, void*) {
	int bb, gg, rr, media;
	for (int n = 0; n < img.rows; n++) {
		for (int m = 0; m < img.cols; m++) {
			bb = img2.at<cv::Vec3b>(n, m)[0];
			gg = img2.at<cv::Vec3b>(n, m)[1];
			rr = img2.at<cv::Vec3b>(n, m)[2];
			media = (bb + rr + gg) / 3;
			if (gg > media && gg > rr && gg > bb) {
				if (g < gg) {
					img.at<cv::Vec3b>(n, m)[0] = (int)media;
					img.at<cv::Vec3b>(n, m)[1] = (int)media;
					img.at<cv::Vec3b>(n, m)[2] = (int)media;
				}
				else {
					img.at<cv::Vec3b>(n, m)[0] = img2.at<cv::Vec3b>(n, m)[0];
					img.at<cv::Vec3b>(n, m)[1] = img2.at<cv::Vec3b>(n, m)[1];
					img.at<cv::Vec3b>(n, m)[2] = img2.at<cv::Vec3b>(n, m)[2];
				}
			}
		}
	}
	imshow("Imagem", img);
}

void b_trackbar(int, void*) {
	int bb, gg, rr, media;
	for (int n = 0; n < img.rows; n++) {
		for (int m = 0; m < img.cols; m++) {
			bb = img2.at<cv::Vec3b>(n, m)[0];
			gg = img2.at<cv::Vec3b>(n, m)[1];
			rr = img2.at<cv::Vec3b>(n, m)[2];
			media = (bb + rr + gg) / 3;
			if (bb > media && bb > rr && bb > gg) {
				if (b < bb) {
					img.at<cv::Vec3b>(n, m)[0] = (int)media;
					img.at<cv::Vec3b>(n, m)[1] = (int)media;
					img.at<cv::Vec3b>(n, m)[2] = (int)media;
				}
				else {
					img.at<cv::Vec3b>(n, m)[0] = img2.at<cv::Vec3b>(n, m)[0];
					img.at<cv::Vec3b>(n, m)[1] = img2.at<cv::Vec3b>(n, m)[1];
					img.at<cv::Vec3b>(n, m)[2] = img2.at<cv::Vec3b>(n, m)[2];
				}
			}
		}
	}
	imshow("Imagem", img);
}

int main()
{
	img = imread("caminho da sua imagem", IMREAD_COLOR);  //imagem que será apresentada
	img2 = imread("caminho da sua imagem", IMREAD_COLOR); //mesma imagem, será usada como referencia 
							  //e seus dados nunca devem ser alterados
	namedWindow("Imagem", 1);
	createTrackbar("R", "Imagem", &r, 255, r_trackbar);
	createTrackbar("G", "Imagem", &g, 255, g_trackbar);
	createTrackbar("B", "Imagem", &b, 255, b_trackbar);
	imshow("Imagem", img);

	waitKey(0);
	return 0;
}
