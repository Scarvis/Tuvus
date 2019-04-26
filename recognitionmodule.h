#ifndef RECOGNITIONMODULE_H
#define RECOGNITIONMODULE_H

#include "recognitionresults.h"
#include "patternrecognitionmodule.h"
#include <baseapi.h>
#include <allheaders.h>

class RecognitionModule
{
public:
    RecognitionModule();
    RecognitionResults startRecognition(patternRecognitionModule pattern);

private:
    QString recognize(InfoClass args);
    tesseract::TessBaseAPI *recognitionApi;
};

#endif // RECOGNITIONMODULE_H
