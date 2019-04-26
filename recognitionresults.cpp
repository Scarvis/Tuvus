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
