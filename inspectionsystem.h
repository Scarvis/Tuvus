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
    Q_OBJECT
    Q_PROPERTY(QVector<int> statusDocuments READ getCurrentStatusDocument CONSTANT)
    //Q_PROPERTY(DocumentsListModule documentsListMod READ getDocListModItem CONSTANT)
    //Q_PROPERTY(QVector<documentsListItem> documentsListM READ getDocListItem CONSTANT)
public:
    inspectionSystem();
    inspectionSystem(QString str);
    int recognition(patternRecognitionModule pattern);

public Q_SLOTS:
    void loadFile(const QUrl &fileUrl);
    void loadFolder(const QUrl &folderUrl);
    void recognizeCurrentFolder();
    void recognizeCurrentFile();
    QString getPathFile(const int index);
    QVector<int> getCurrentStatusDocument() const;
    //QVector<documentsListItem> getDocListItem() const;
    //DocumentsListModule getDocListModItem() const;


private:
    patternRecognitionModule patternRecModule;
    RecognitionModule recognitionModule;
    DocumentHandler documentHandler;
    DocumentsListModule documentsListModule;
    //DocumentsListModule documentsListMod;
    //QVector<documentsListItem> documentsListModul;

    QVector<RecognitionResults> currentRecognitionResults;
    QUrl currentFileUrl;
    QUrl currentFolderUrl;
    QUrl lastRecognitionFolder = QUrl::fromLocalFile("21.PNG");
    QUrl lastRecognitionFile;
    int testP = 0;
};

#endif // INSPECTIONSYSTEM_H
