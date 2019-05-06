#include "documentslistmodule.h"
#include <iostream>
#include <QDebug>
#include <stdlib.h>

DocumentsListModule::DocumentsListModule(QObject *parent) : QObject(parent)
{
    mItems.append({"Example_2-1.PNG", "example"});
    mItems.append({"Example_2-1.PNG", "example"});
    mItems.append({"background.png", "backround"});
    statusDocuments.fill(0,mItems.size());
    srand(time_t(NULL));
    rightAnswersArray.fill(1, 60);
    for (int i = 0; i < 60; i++) {
        rightAnswersArray[i] = rand() % 6 + 1;
    }
}

bool DocumentsListModule::setItemAt(int index, const documentsListItem &item)
{
    if (index < 0 || index >= mItems.size())
            return false;
    const documentsListItem &oldItem = mItems.at(index);
    if (item.pathFile == oldItem.pathFile && item.nameFile == oldItem.nameFile)
        return false;

    mItems[index] = item;
    return true;
}

QVector<documentsListItem> DocumentsListModule::items() const
{
    return mItems;
}

QString DocumentsListModule::getItem(const int index) //from inspectionsystem
{
    if(mItems.count() <= 0)
        return "";
    if(index > mItems.count())
    {
        mCurrentIndexClicked = 0;
        return "";
    }
    return mItems.at(index).pathFile;
}

QVector<int> DocumentsListModule::getCurrentStatusDocument() const //from inspectionsystem
{
    return statusDocuments;
}

int DocumentsListModule::currentIndexClicked()
{
    return mCurrentIndexClicked;
}

void DocumentsListModule::setIndexClicked(int indexClicked)
{
    mCurrentIndexClicked = indexClicked;
    currentPathFile = mItems.at(mCurrentIndexClicked).pathFile;
}

QString DocumentsListModule::getItem()
{
    if(mItems.count() <= 0)
        return "";
    if(mCurrentIndexClicked > mItems.count())
    {
        mCurrentIndexClicked = 0;
        return "";
    }
    return mItems.at(mCurrentIndexClicked).pathFile;
}

QVector<int> DocumentsListModule::currentStatusDocument() const
{
    if(statusDocuments.size() <= 0)
    {
        return statusDocuments;
    }
    return statusDocuments;
}

int DocumentsListModule::getCurrentIndexClicked() const //from inspection system
{
    return mCurrentIndexClicked;
}

QVector<int> DocumentsListModule::getRecognizeIssuesResults() const
{
    return recognizeQuestionsResult;
}

QVector<int> DocumentsListModule::getRightAnswersArray() const
{
    return rightAnswersArray;
}

void DocumentsListModule::startRecognition()
{
    //statusDocuments.clear();
    statusDocuments.fill(0,mItems.size());
    for (int i = 0; i < mItems.size(); i++) {
        statusDocuments[i] = 1;
    }
    srand(time_t(NULL));
    recognizeQuestionsResult.fill(1, 60);
    for (int i = 0; i < 60; i++) {
        recognizeQuestionsResult[i] = rand() % 6 + 1;
    }

}

QImage DocumentsListModule::cropImage(QImage original, QRect rect)
{
    //QRect rect(10, 20, 30, 40);
    //QImage original('image.png');
    QImage cropped = original.copy(rect);
    return cropped;
}

QString DocumentsListModule::getCurrentCropQuestion(int index)
{
    QImage orig; orig.load(currentPathFile);
    if(!orig.load(currentPathFile)){
        qDebug() << orig << currentPathFile;
        exit(-1);
    }
    int it = 10, x = 190;
    if(index - 1 < it) it = index - 1;
    for(int i = 0; i < it; i++)
    {
        x += 76;
    }
    QImage res = cropImage(orig, QRect(x, 120, 75, 60));
     // Some init code to setup the image (e.g. loading a PGN/JPEG, etc.)
    QByteArray bArray;
    QBuffer buffer(&bArray);
    buffer.open(QIODevice::WriteOnly);
    res.save(&buffer, "JPG");
    QString image("data:image/jpg;base64,");
    image.append(QString::fromLatin1(bArray.toBase64().data()));
    return image;
}



void DocumentsListModule::appendItem()
{
    emit preItemAppend();


    documentsListItem document;
    document.pathFile = QString("Example_2-1.PNG");
    document.nameFile = QString("11");
    mItems.append(document);

    emit postItemAppend();
}
