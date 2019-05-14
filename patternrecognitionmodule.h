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
    QVector<InfoClass> getRecognitionArea();
	int getSizeRecognitionArea() const;
    patternRecognitionModule operator=(const patternRecognitionModule right){
        if(this == &right){
            return *this;
        }
        recognitionArea = right.recognitionArea;
        QVector<InfoClass> questionsAnswersInfo = right.questionsAnswersInfo;
        countQuestion = right.countQuestion;
        numbersOfReplies = right.numbersOfReplies;
        answerNumber = right.answerNumber;
        defaultNumbersOfCorrectReplies = right.defaultNumbersOfCorrectReplies;
        indentBetweenQuestions = right.indentBetweenQuestions;
        isOkCurrentPattern = right.isOkCurrentPattern;

        return *this;
    }
private:
    int countQuestion = 0;
    int numbersOfReplies = 0;
    int answerNumber = 0;
    int defaultNumbersOfCorrectReplies = 0;
    double indentBetweenQuestions = 0;
    QVector<InfoClass> questionsAnswersInfo;
    QVector<InfoClass> recognitionArea;
    int isOkCurrentPattern = 1;
    JsonParseClass jsonParse;

    const QString testPatternFileName = "/src/patterns/test_pattern.json";
    const QDir testPatternFilePath = QDir::currentPath() + testPatternFileName;

};

#endif // PATTERNRECOGNITIONMODULE_H
