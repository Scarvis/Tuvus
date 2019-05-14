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
	QString getRecognitionResultsString() const;
	void clear();
private:
    QString outputString = "";
    QString errorString = "";
    bool isOkLast = true;
};

#endif // RECOGNITIONRESULTS_H
