#include "documentprocessormodule.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QDebug>

using namespace cv;


DocumentProcessorModule::DocumentProcessorModule()
{
}

DocumentProcessorModule::~DocumentProcessorModule()
{
}

QImage DocumentProcessorModule::preliminaryProcessing(QString objRecogPath)
{
	return QImage();
}

QImage DocumentProcessorModule::getGrayscale(QString imagePath)
{
	//IplImage *img = cvLoadImage(imagePath.toStdString());
	Mat image;
	image = imread("C:\Temp\lena.jpg", IMREAD_COLOR);
	if (image.empty()) {
		qDebug() << "dont load image getGrayscale, documentProcessorModule";
		return QImage();
	}
	Mat gray;
	cv::cvtColor(image, gray, COLOR_RGB2GRAY);
	QImage retImage((uchar*)gray.data, gray.cols, gray.rows, QImage::Format_RGB888);
	/*namedWindow("Result window", WINDOW_AUTOSIZE);
	imshow("Result window", gray);

	waitKey(0);*/
	return retImage;
}
