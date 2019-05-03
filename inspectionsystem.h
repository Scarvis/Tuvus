#ifndef INSPECTIONSYSTEM_H
#define INSPECTIONSYSTEM_H

#include <QObject>
#include "patternrecognitionmodule.h"
#include "jsonparseclass.h"
#include "infoclass.h"
#include "recognitionmodule.h"
#include "documentslistmodule.h"
#include "documenthandler.h"

class inspectionSystem : public QObject
{
public:
    inspectionSystem();
    inspectionSystem(QString str);
    int recognition(patternRecognitionModule pattern);

public Q_SLOTS:
    void loadFile(const QUrl &fileUrl);
    void loadFolder(const QUrl &folderUrl);
    void recognize();
    QString getPathFile(const int index);
    QVector<int> currentStatusDocument() const;




private:
    patternRecognitionModule patternRecModule;
    RecognitionModule recognitionModule;
    DocumentsListModule documentsListModule;
    DocumentHandler documentHandler;
    QUrl currentFileUrl;
    QUrl currentFolderUrl;
};

#endif // INSPECTIONSYSTEM_H
