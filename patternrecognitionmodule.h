#ifndef PATTERNRECOGNITIONMODULE_H
#define PATTERNRECOGNITIONMODULE_H
#include <QString>
#include <iostream>
#include <QDir>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

class patternRecognitionModule
{
public:
    patternRecognitionModule();
    patternRecognitionModule(QString str);
    int setNewPatternRecognition(QString str);
    int isOk() const;
private:
    int countQuestion = 0;
    int numbersOfReplies = 0;
    int answerNumber = 0;
    int defaultNumbersOfCorrectReplies = 0;
    double indentBetweenQuestions = 0;
    const QString testPatternFileName = "test_pattern.json";
    QDir testPatternFilePath = QDir::currentPath() + "/" + testPatternFileName;
    QString jsonString = "";
    int isOkCurrentPattern = 0;
};

#endif // PATTERNRECOGNITIONMODULE_H
