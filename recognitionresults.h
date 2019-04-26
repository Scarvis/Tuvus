#ifndef RECOGNITIONRESULTS_H
#define RECOGNITIONRESULTS_H

#include <QString>
#include <QVector>

class RecognitionResults
{
public:
    RecognitionResults();
    QString outputFile();
    void addRecognitionResults(QString str);
private:
    QString outputString;
    QString errorString;
    bool isOkLast = true;
};

#endif // RECOGNITIONRESULTS_H
