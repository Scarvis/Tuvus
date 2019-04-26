#ifndef INSPECTIONSYSTEM_H
#define INSPECTIONSYSTEM_H

#include <QObject>
#include "patternrecognitionmodule.h"
#include "jsonparseclass.h"
#include "infoclass.h"
#include "recognitionmodule.h"

class inspectionSystem
{
public:
    inspectionSystem();
    inspectionSystem(QString str);
    int recognition(patternRecognitionModule pattern);
private:
    patternRecognitionModule patternRecModule;
    RecognitionModule recognitionModule;
};

#endif // INSPECTIONSYSTEM_H
