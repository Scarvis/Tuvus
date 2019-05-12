#include "inspectionsystem.h"
#include "recognitionresults.h"

inspectionSystem::inspectionSystem()
{
    //documentsListModul.append({"Example_2-1.PNG", "example"});
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
    qDebug() << "folderUrl: " << folderUrl << ". test = " << testP++;
    if(folderUrl == currentFolderUrl)
        return;
    documentHandler.loadFolder(folderUrl);
    currentFolderUrl = folderUrl;
}

void inspectionSystem::recognizeCurrentFile()
{
    if(lastRecognitionFile == currentFileUrl)
        return;
}

void inspectionSystem::recognizeCurrentFolder()
{
    if(lastRecognitionFolder == currentFolderUrl)
        return;

    QImage img("21.PNG");
    QString bf = recognitionModule.recognize(img);
    qDebug() << "rec results" << bf;
    return;



    QVector<documentsListItem> currentArrayObjectRecognition = documentsListModule.items();
    QVector<RecognitionResults> recResult;
    for (int i = 0; i < currentArrayObjectRecognition.size(); ++i) {
        QImage res(currentArrayObjectRecognition[i].pathFile);
        RecognitionResults recognitionResults = recognitionModule.startRecognition(
                    res,
                    patternRecModule
                    );
        recResult.append(recognitionResults);
    }
    lastRecognitionFolder = currentFolderUrl;
}

QString inspectionSystem::getPathFile(const int index)
{
    return documentsListModule.getItem(index);
}

QVector<int> inspectionSystem::getCurrentStatusDocument() const
{
    return documentsListModule.getCurrentStatusDocument();
}

//QVector<documentsListItem> inspectionSystem::getDocListItem() const
//{
//    return documentsListModul;
//}
//
//DocumentsListModule inspectionSystem::getDocListModItem() const
//{
//    return documentsListMod;
//}
