#ifndef RECOGNITIONMODULE_H
#define RECOGNITIONMODULE_H

#include "recognitionresults.h"
#include "patternrecognitionmodule.h"
#include <baseapi.h>
#include <allheaders.h>


class RecognitionModule
{
public:
    RecognitionModule();
    ~RecognitionModule();
    RecognitionResults startRecognition(QImage objectRecognition, patternRecognitionModule pattern);
    QString recognize(QImage objectRecognition);
    void setPatternRecognition(patternRecognitionModule pattern);
    patternRecognitionModule getPatternRecognition() const;
private:
    tesseract::TessBaseAPI *recognitionApi;
    patternRecognitionModule patternRec;
    //PIX* makePIXFromQImage(const QImage &image);
    QImage PIX2QImage(PIX *pixImage);
    PIX* qImage2PIX(QImage& qImage);
    QImage cropImage(QImage original, QRect rect);
    QString recognize(QImage objectRecognition, patternRecognitionModule pattern);
    QString recognize(QImage objectRecognition, InfoClass recognitionArea);


};

#endif // RECOGNITIONMODULE_H
