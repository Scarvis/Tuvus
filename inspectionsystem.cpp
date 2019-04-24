#include "inspectionsystem.h"

inspectionSystem::inspectionSystem()
{

}

inspectionSystem::inspectionSystem(QString str)
{
    if(str == "test")
    {
        if(patternRecModule.setTestPatternRecognition() == -1)
            qDebug() << "hui";
    }
}
