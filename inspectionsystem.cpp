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
    //RecognitionResults results = recognitionModule.startRecognition(pattern);
    return 0;
}

void inspectionSystem::loadFile(const QUrl &fileUrl)
{
    if(fileUrl == currentFileUrl)
        return;
    documentHandler.loadFile(fileUrl);
    currentFileUrl = fileUrl;
}

void inspectionSystem::loadFolder(const QUrl &folderUrl)
{
    if(folderUrl == currentFolderUrl)
        return;
    documentHandler.loadFolder(folderUrl);
    currentFolderUrl = folderUrl;
}

QString inspectionSystem::getPathFile(const int index)
{
    return documentsListModule.getItem(index);
}

QVector<int> inspectionSystem::currentStatusDocument() const
{
    return QVector<int>();
}
