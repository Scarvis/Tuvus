#include "documentslistmodule.h"
#include <iostream>
#include <QDebug>
#include <stdlib.h>

DocumentsListModule::DocumentsListModule(QObject *parent) : QObject(parent)
{
    mItems.append({ "file:C://Users//Mikhail//Documents//QMLTestApp//Scan1.png", "example"});
    //mItems.append({"Example_2-1.PNG", "example"});
    //mItems.append({ "file:C://Users//Mikhail//Documents//QMLTestApp//dashi.png", "backround"});
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

QVector<QString> DocumentsListModule::getPathFilesItems() const
{
	QVector<QString> res;
	for (int i = 0; i < mItems.size(); i++) 
	{
		res.append(mItems[i].pathFile);
	}
	return res;
}

QVector<int> DocumentsListModule::getCurrentStatusDocument() const //from inspectionsystem
{
    return statusDocuments;
}

void DocumentsListModule::appendItem(documentsListItem item)  //from inspectionsystem
{
	mItems.append(item);
}

void DocumentsListModule::appendItem(QString item)
{
	mItems.append({ item, "null"});
}

void DocumentsListModule::clear()
{
	mItems.clear();
	int mCurrentIndexClicked = 0;
	QString currentPathFile = "Example_2-1.PNG";
	statusDocuments.clear();
	recognizeQuestionsResult.clear();
	rightAnswersArray.clear();
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
    if(mCurrentIndexClicked >= mItems.count())
    {
        mCurrentIndexClicked = 0;
        return "";
    }
    return mItems.at(mCurrentIndexClicked).pathFile;
}

QString DocumentsListModule::getItem(int index) const
{
	if (index < 0 || index >= mItems.size() - 1)
		return QString();
	return mItems.at(index).pathFile;
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
    QImage cropped = original.copy(rect);
    return cropped;
}

QImage DocumentsListModule::cropImage(QImage original, InfoClass infoClass)
{
	QRect rect = infoClass.getQRect();
	QImage cropped = original.copy(rect);
	return cropped;
}

QString DocumentsListModule::getCurrentDocumentName() const
{
	if (mCurrentIndexClicked >= mItems.size())
		return QString("Error, current index more size");
	return mItems[mCurrentIndexClicked].nameFile;
}

QString DocumentsListModule::getCurrentCropQuestion(int index)
{
    QImage orig; orig.load(currentPathFile);
    if(!orig.load(currentPathFile)){
        qDebug() << orig << currentPathFile;
		return QString();
    }
    int it = 10, x = 190;
    if(index - 1 < it) it = index - 1;
    for(int i = 0; i < it; i++)
    {
        x += 76;
    }
    QImage res = cropImage(orig, QRect(x - 37.5, 120, 130, 60));
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
