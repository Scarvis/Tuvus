#include "recognitionresults.h"

RecognitionResults::RecognitionResults()
{

}

QString RecognitionResults::outputFile()
{
    return outputString;
}

void RecognitionResults::addRecognitionResults(QString str)
{
	outStrList.append(str);
    outputString += (str);
}

QString RecognitionResults::getRecognitionResultsString() const
{
	return outputString;
}

QVector<QString> RecognitionResults::getRecognitionResultsList() const
{
	return outStrList;
}

void RecognitionResults::clear()
{
	outputString = "";
	errorString = "";
	isOkLast = true;
}
