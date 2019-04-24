#include "patternrecognitionmodule.h"


patternRecognitionModule::patternRecognitionModule()
{
    qDebug() << "DIR: " << testPatternFilePath;
}

patternRecognitionModule::patternRecognitionModule(QString str)
{
    if(str == "test"){

        //QJsonDocument document = QJsonDocument::fromJson()

    }
}

int patternRecognitionModule::setNewPatternRecognition(QString str)
{
    return 0;
}

int patternRecognitionModule::isOk() const
{
    return isOkCurrentPattern;
}
