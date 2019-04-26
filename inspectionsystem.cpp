#include "inspectionsystem.h"
#include "recognitionresults.h"
inspectionSystem::inspectionSystem()
{

}

inspectionSystem::inspectionSystem(QString str)
{
    if(str == "test")
    {
        if(patternRecModule.setTestPatternRecognition() == -1)
            qDebug() << "inspect";
    }
}

int inspectionSystem::recognition(patternRecognitionModule pattern)
{
    RecognitionResults results = recognitionModule.startRecognition(pattern);
    return 0;
}
