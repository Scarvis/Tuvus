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
	QVector<QString> getRecognitionResultsList() const;
	void clear();
private:
	QVector<QString> outStrList;
    QString outputString = "";
    QString errorString = "";
    bool isOkLast = true;
};

#endif // RECOGNITIONRESULTS_H
