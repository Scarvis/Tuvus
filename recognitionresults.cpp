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
    outputString += str;
}

QString RecognitionResults::getRecognitionResultsString() const
{
	return outputString;
}

void RecognitionResults::clear()
{
	outputString = "";
	errorString = "";
	isOkLast = true;
}
