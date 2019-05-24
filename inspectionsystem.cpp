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
            qDebug() << "test pattern recognition not init";
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

	lastRecognitionFile = currentFileUrl;
}

void inspectionSystem::recognizeCurrentFolder()
{
    if(lastRecognitionFolder == currentFolderUrl)
        return;

    QImage img("21.PNG");
    QString bf = recognitionModule.recognize(img);
    qDebug() << "rec results" << bf;
    //return;



    QVector<documentsListItem> currentArrayObjectRecognition = documentsListModule.items();
    QVector<RecognitionResults> recResult;
	QVector<InfoClass> recognitionArea = patternRecModule.getRecognitionArea();
    for (int i = 0; i < currentArrayObjectRecognition.size(); ++i) 
	{
        QImage res(currentArrayObjectRecognition[i].pathFile);
		for (int j = 0; j < recognitionArea.size(); j++) 
		{
			if (recognitionArea[j].isQuest()) 
			{
				QVector<InfoClass> answerRecArea = patternRecModule.getAnswerRecognitionArea();
				for (int answerIndex = 0; answerIndex < answerRecArea.size(); answerIndex++)
				{
					RecognitionResults recognitionResults = recognitionModule.startRecognition(
						res,
						recognitionArea[j],
						answerRecArea[answerIndex]
					);
					recResult.append(recognitionResults);
				}
			}
			else
			{

			}
		}
        /*RecognitionResults recognitionResults = recognitionModule.startRecognition(
                    res,
                    patternRecModule
                    );
        recResult.append(recognitionResults);*/
		break;
    }
	QFile file("testtxt.txt");
	file.open(QIODevice::WriteOnly | QIODevice::Text);
	for (int i = 0; i < recResult.size(); i++) {
		file.write(recResult[i].outputFile().toLocal8Bit());
	}
	file.close();
	maxIndexCroppedQuestionImage = patternRecModule.getSizeRecognitionArea();
	currentRecognitionResults = recResult;
	currentRecognitionDocument.load(currentArrayObjectRecognition[0].pathFile);
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

QString inspectionSystem::getCurrentCloseUpDocumentRecognizeResult(int index) const  //from QML
{
	if(index - 1 >= currentRecognitionResults.size() || index - 1 < 0)
		return QString();
	return currentRecognitionResults[index - 1].getRecognitionResultsString();
}

bool inspectionSystem::setDocumentsList(QVector<QString> mItems, int currentIndexClicked)
{
	documentsListModule.clear();
	
	for (int i = 0; i < mItems.size(); i++)
	{
		documentsListModule.appendItem(mItems[i]);
		qDebug() << mItems[i];
	}
	documentsListModule.setIndexClicked(currentIndexClicked);
	return true;
}

int inspectionSystem::getMaxIndexCroppedQuestionImage() const
{
	return maxIndexCroppedQuestionImage;
}

QString inspectionSystem::getCurrentCropQuestion(int index) //QML
{
	QImage orig(documentsListModule.getItem());
	if (orig.isNull()) {
		qDebug() << "dont download image, getCurrentCropQuestion";
		return QString();
	}
	
	// Some init code to setup the image (e.g. loading a PGN/JPEG, etc.)
	QImage res = documentsListModule.cropImage(orig, patternRecModule.getRecognitionAreaAt(index));
	QByteArray bArray;
	QBuffer buffer(&bArray);
	buffer.open(QIODevice::WriteOnly);
	res.save(&buffer, "JPG");
	QString image("data:image/jpg;base64,");
	image.append(QString::fromLatin1(bArray.toBase64().data()));
	return image;
}

