#include "recognitionmodule.h"
#include "patternrecognitionmodule.h"
#include "infoclass.h"

RecognitionModule::RecognitionModule()
{
    recognitionApi = new tesseract::TessBaseAPI();
}

RecognitionResults RecognitionModule::startRecognition(patternRecognitionModule pattern)
{
    RecognitionResults res;
    QVector<InfoClass> recArea = pattern.getRecognitionArea();
    for (int i = 0; i < recArea.size(); i++) {
        QString result = recognize(recArea[i]);
        res.addRecognitionResults(result);
    }


    return res;
}

QString RecognitionModule::recognize(InfoClass args)
{
    QString output;

    return output;
}
