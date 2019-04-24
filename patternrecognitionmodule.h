#ifndef PATTERNRECOGNITIONMODULE_H
#define PATTERNRECOGNITIONMODULE_H
#include <QString>
#include <iostream>
#include <QDir>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QJsonParseError>
#include "jsonparseclass.h"
#include "infoclass.h"

class patternRecognitionModule
{
public:
    patternRecognitionModule();
    patternRecognitionModule(QString str);
    int setNewPatternRecognition(QString str);
    int isOk() const;
    int setTestPatternRecognition();
private:
    int countQuestion = 0;
    int numbersOfReplies = 0;
    int answerNumber = 0;
    int defaultNumbersOfCorrectReplies = 0;
    double indentBetweenQuestions = 0;
    QVector<InfoClass> questionsAnswersInfo;

    const QString testPatternFileName = "/src/patterns/test_pattern.json";
    QDir testPatternFilePath = QDir::currentPath() + testPatternFileName;
    QString jsonString = "";
    int isOkCurrentPattern = 0;
    JsonParseClass jsonParse;

};

#endif // PATTERNRECOGNITIONMODULE_H
