#include "recognitionmodule.h"
#include "patternrecognitionmodule.h"
#include "infoclass.h"
#include <QImage>
#include <QBuffer>

RecognitionModule::RecognitionModule()
{
    recognitionApi = new tesseract::TessBaseAPI();
    if(recognitionApi->Init(NULL, "eng")){
        qDebug() << "failed to init api";
        exit(4);
    }
}

RecognitionModule::~RecognitionModule()
{
    recognitionApi->End();
}

QImage RecognitionModule::cropImage(QImage original, QRect rect)
{
    //QRect rect(10, 20, 30, 40);
    //QImage original('image.png');
    QImage cropped = original.copy(rect);
    return cropped;
}

RecognitionResults RecognitionModule::startRecognition(QImage objectRecognition, patternRecognitionModule pattern)
{
    RecognitionResults res;
    QVector<InfoClass> recArea = pattern.getRecognitionArea();
    QImage objRecog = objectRecognition;
    for (int i = 0; i < recArea.size(); i++) {
        QRect rect = recArea[i].getQRect();
        QImage recImage = cropImage(objRecog, rect);
        QString result = recognize(recImage);
        res.addRecognitionResults(result);
    }
    return res;
}

void RecognitionModule::setPatternRecognition(patternRecognitionModule pattern)
{
    patternRec = pattern;
}

patternRecognitionModule RecognitionModule::getPatternRecognition() const
{
    return patternRec;
}

//PIX* RecognitionModule::makePIXFromQImage(const QImage &image)
//{
//    QByteArray ba;
//    QBuffer buf(&ba);
//    buf.open(QIODevice::WriteOnly);
//    image.save(&buf, "BMP");
//    return pixReadMemBmp(ba.constData(), ba.size());
//}

QImage RecognitionModule::PIX2QImage(PIX *pixImage) {
    int width = pixGetWidth(pixImage);
    int height = pixGetHeight(pixImage);
    int depth = pixGetDepth(pixImage);
    int bytesPerLine = pixGetWpl(pixImage) * 4;
    l_uint32 * s_data = pixGetData(pixEndianByteSwapNew(pixImage));

    QImage::Format format;
    if (depth == 1)
        format = QImage::Format_Mono;
    else if (depth == 8)
        format = QImage::Format_Indexed8;
    else
        format = QImage::Format_RGB32;

    QImage result((uchar*)s_data, width, height, bytesPerLine, format);

      // Handle pallete
    QVector<QRgb> _bwCT;
    _bwCT.append(qRgb(255,255,255));
    _bwCT.append(qRgb(0,0,0));

    QVector<QRgb> _grayscaleCT(256);
    for (int i = 0; i < 256; i++)  {
        _grayscaleCT.append(qRgb(i, i, i));
    }
    if (depth == 1) {
        result.setColorTable(_bwCT);
    }  else if (depth == 8)  {
        result.setColorTable(_grayscaleCT);
    } else {
        result.setColorTable(_grayscaleCT);
    }

    if (result.isNull()) {
        static QImage none(0,0,QImage::Format_Invalid);
        qDebug() << "***Invalid format!!!";
        return none;
    }

    return result.rgbSwapped();
}

PIX* RecognitionModule::qImage2PIX(QImage& qImage) {
    PIX * pixs;
    l_uint32 *lines;

    qImage = qImage.rgbSwapped();
    int width = qImage.width();
    int height = qImage.height();
    int depth = qImage.depth();
    int wpl = qImage.bytesPerLine() / 4;
    pixs = pixCreate(width, height, depth);
    pixSetWpl(pixs, wpl);
    pixSetColormap(pixs, NULL);
    l_uint32 *datas = pixs->data;

    for (int y = 0; y < height; y++) {
        lines = datas + y * wpl;
        QByteArray a((const char*)qImage.scanLine(y), qImage.bytesPerLine());
        for (int j = 0; j < a.size(); j++) {
            *((l_uint8 *)lines + j) = a[j];
        }
    }
    return pixEndianByteSwapNew(pixs);
}

QString RecognitionModule::recognize(QImage objectRecognition)
{
    Pix *pixImage = qImage2PIX(objectRecognition);
    QString output = "";
    recognitionApi->SetImage(pixImage);
    output = recognitionApi->GetUTF8Text();
    return output;
}



QString RecognitionModule::recognize(QImage objectRecognition, patternRecognitionModule pattern)
{
    QString output = "";

    return output;
}

QString RecognitionModule::recognize(QImage objectRecognition, InfoClass recognitionArea)
{
    QString output = "";

    return output;
}
