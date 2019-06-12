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
#include <QUrl>
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
	int setRightAnswers();
	QVector<QString> getRightAnswersList() const;
    QVector<InfoClass> getRecognitionArea() const;
	InfoClass getRecognitionAreaAt(int index) const;
	QVector<InfoClass> getAnswerRecognitionArea() const;
	int getSizeRecognitionArea() const;
	QString getPatternsPath() const;
	QString getAnswersFilesPath() const;
	bool saveNewPatternRecognition(const QUrl &fileUrl, QVector<QString> x, QVector<QString> y, QVector<QString> width, QVector<QString> height);
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
	void generateRandomAnswers();
    int countQuestion = 0;
    int numbersOfReplies = 0;
    int answerNumber = 0;
    int defaultNumbersOfCorrectReplies = 0;
    double indentBetweenQuestions = 0;
    QVector<InfoClass> questionsAnswersInfo;
    QVector<InfoClass> recognitionArea;
	QVector<QString> listAnswers;
    int isOkCurrentPattern = 1;
    JsonParseClass jsonParse;
	const QString patternsPath = QDir::currentPath() + "/src/patterns/";
	const QString answersFilesPath = QDir::currentPath() + "/src/answers_reference/";
    const QString testPatternFileName = "/src/patterns/test_pattern.json";
    const QDir testPatternFilePath = QDir::currentPath() + testPatternFileName;
};

#endif // PATTERNRECOGNITIONMODULE_H
