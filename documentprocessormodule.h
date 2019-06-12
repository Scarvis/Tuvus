#pragma once

#include <QImage>

class DocumentProcessorModule
{
public:
	DocumentProcessorModule();
	~DocumentProcessorModule();

	QImage preliminaryProcessing(QString objRecogPath);
	QImage getGrayscale(QString imagePath);
	QImage getBinarization(QString imagePath);
	QImage getContur(QString imagePath);
};
	