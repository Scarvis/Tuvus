#ifndef INSPECTIONSYSTEM_H
#define INSPECTIONSYSTEM_H

#include <QObject>
#include "patternrecognitionmodule.h"
#include "jsonparseclass.h"
#include "infoclass.h"

class inspectionSystem
{
public:
    inspectionSystem();
    inspectionSystem(QString str);
private:
    patternRecognitionModule patternRecModule;
};

#endif // INSPECTIONSYSTEM_H
