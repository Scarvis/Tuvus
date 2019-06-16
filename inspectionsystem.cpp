#include "inspectionsystem.h"
#include "recognitionresults.h"
#include <QProcess>

inspectionSystem::inspectionSystem()
{

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

void inspectionSystem::recognizeSymbolsWithPython()
{
	QString path = QDir::currentPath() + "/src";
	QString  command("python");
	QStringList params = QStringList() << "qwe.py";

	QProcess *process = new QProcess();
	process->startDetached(command, params, path);
	process->waitForFinished();
	process->close();
}

void inspectionSystem::recognizeCurrentFolder()
{
    if(lastRecognitionFolder == currentFolderUrl)
        return;

   
	currentRightAnswers = patternRecModule.getRightAnswersList();

    QVector<documentsListItem> currentArrayObjectRecognition = documentsListModule.items();
    QVector<RecognitionResults> recResult;
	QVector<InfoClass> recognitionArea = patternRecModule.getRecognitionArea();
	
	QFile fileInfo("src\\info.txt");
	fileInfo.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream stream(&fileInfo);
	stream << QString::number(recognitionArea.size());
	fileInfo.close();
    for (int i = 0; i < currentArrayObjectRecognition.size(); ++i) 
	{
		//QImage res(documentProcessorModule.getGrayscale(currentArrayObjectRecognition[i].pathFile));
		QString pathFileAfterCheck = checkPathFileForFile(currentArrayObjectRecognition[i].pathFile);
        QImage res(pathFileAfterCheck);
		recognizeSymbolsWithPython();
		currentRecognizedIssues = parseTextFileAfterPythonScript();
		/*for (int j = 0; j < recognitionArea.size(); j++) 
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
				RecognitionResults recognitionResults = recognitionModule.startRecognition(
					res,
					recognitionArea[j]
				);
				recResult.append(recognitionResults);
				currentRecognizedIssues.append(recognitionResults.getRecognitionResultsString());
			}
		}*/
       
		break;
    }

	maxIndexCroppedQuestionImage = patternRecModule.getSizeRecognitionArea();
	//currentRecognitionResults = recResult;
	//currentRecognitionDocument.load(currentArrayObjectRecognition[0].pathFile);
    lastRecognitionFolder = currentFolderUrl;

	int rigA = 0, urigA = 0;
	for (int i = 0; i < currentRecognizedIssues.size(); i++) {
		if (currentRecognizedIssues[i] == currentRightAnswers[i])
			rigA++;
		else
			urigA++;
	}
	countRightAnswer = rigA;
	recognitionPercentage = double(double(rigA) / double(currentRecognizedIssues.size()));
	QString tStr = QString::number(recognitionPercentage, 'f', 2);
	recognitionPercentage = tStr.toDouble();
}

QString inspectionSystem::getPathFile(const int index)
{
    return documentsListModule.getItem(index);
}

QVector<int> inspectionSystem::getCurrentStatusDocument() const
{
    return documentsListModule.getCurrentStatusDocument();
}

QVector<QString> inspectionSystem::getRightAnswersList() const
{
	return currentRightAnswers;
	//return currentRecognitionResults[currentIndexDocumentInQueue].getRecognitionResultsList();
}

QVector<QString> inspectionSystem::getRecognizedIssuesList() const
{
	return currentRecognizedIssues;
}

QString inspectionSystem::getCurrentCloseUpDocumentRecognizeResult(int index) const  //from QML
{
	if(index - 1 >= currentRecognizedIssues.size() || index - 1 < 0)
		return QString();
	return currentRecognizedIssues[index - 1];
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
	QString pathOrig = documentsListModule.getItem();
	pathOrig = checkPathFileForFile(pathOrig);
	QImage orig(pathOrig);
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

QString inspectionSystem::getCropImage(QString pathFile, QString x, QString y, QString width, QString height)
{
	QImage orig(pathFile);
	if (orig.isNull()) {
		qDebug() << "dont download image, inspection system getCropImage";
		return QString();
	}
	InfoClass infoClass(x, y, width, height);
	QImage res = documentsListModule.cropImage(orig, infoClass.getQRect());
	QByteArray bArray;
	QBuffer buffer(&bArray);
	buffer.open(QIODevice::WriteOnly);
	res.save(&buffer, "JPG");
	QString image("data:image/jpg;base64,");
	image.append(QString::fromLatin1(bArray.toBase64().data()));
	return image;
}

QString inspectionSystem::getCurrentDocumentName() const
{
	//QString string = documentsListModule.getCurrentDocumentName();
	QString string = QString::fromUtf8(u8"Процент правильных ответов=");
	string += QString::number((recognitionPercentage * 100), 'f', 2);
	string += "%. ";
	string += QString::number(countRightAnswer);
	string += "/";
	string += QString::number(currentRecognizedIssues.size());
	return string;
}

QVector<QString> inspectionSystem::getArrayPatternRecognition() const
{
	QString path = patternRecModule.getPatternsPath();
	QDir dir(path);
	int ok = dir.exists();
	QVector<QString> arr;
	if (ok) {
		dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks );
		dir.setSorting(QDir::Name);
		QFileInfoList list = dir.entryInfoList();

		for (int i = 0; i < list.size(); ++i)
		{
			QFileInfo fileInfo = list.at(i);
			QString fileName = fileInfo.fileName();
			if (fileName.right(4) == "json")
				arr.append(fileName.left(fileName.size() - 4));
		}
	}
	return arr;
}

QVector<QString> inspectionSystem::getArrayFileAnswers() const
{
	QString path = patternRecModule.getAnswersFilesPath();
	QDir dir(path);
	int ok = dir.exists();
	QVector<QString> arr;
	if (ok) {
		dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
		dir.setSorting(QDir::Name);
		QFileInfoList list = dir.entryInfoList();

		for (int i = 0; i < list.size(); ++i)
		{
			QFileInfo fileInfo = list.at(i);
			QString fileName = fileInfo.fileName();
			if (fileName.right(4) == "json")
				arr.append(fileName.left(fileName.size() - 4));
		}
	}
	return arr;
}

bool inspectionSystem::savePatternRecognition(const QUrl &fileUrl, QVector<QString> x, QVector<QString> y, QVector<QString> width, QVector<QString> height)
{
	bool ok = patternRecModule.saveNewPatternRecognition(
		fileUrl,
		x,
		y,
		width,
		height
	);
	return ok;
}

void inspectionSystem::saveImageCrop()
{
	QString pathOrig = documentsListModule.getItem();
	pathOrig = checkPathFileForFile(pathOrig);
	QImage orig(pathOrig);
	if (orig.isNull()) {
		qDebug() << "dont download image, getCurrentCropQuestion";
		return;
	}

	// Some init code to setup the image (e.g. loading a PGN/JPEG, etc.)
	QVector<InfoClass> recognitionArea = patternRecModule.getRecognitionArea();
	const QString imagesPath = QDir::currentPath() + "/src/images/";
	for (int index = 0; index < recognitionArea.size(); index++) {
		QImage res = documentsListModule.cropImage(orig, recognitionArea[index]);
		QString debS = imagesPath + QString::number(index + 1) + ".png";
		res.save(debS, "png");
	}
}

bool inspectionSystem::setPatternRecognition()
{
	bool ok = patternRecModule.setNewPatternRecognition("test2");
	return ok;
}

void inspectionSystem::changeCurrentCloseUpDocumentRecognizeResult(int index, QString text)
{
    if (index - 1 >= currentRecognizedIssues.size() || index - 1 < 0)
        return;
    if (text.length() > 0)
        currentRecognizedIssues[index - 1] = text;
}

QString inspectionSystem::checkPathFileForFile(QString pathFile)
{
	QString res = pathFile.left(5);
	if (res == "file:")
		return pathFile.right(pathFile.size() - 5);
	return pathFile;
}

QVector<QString> inspectionSystem::parseTextFileAfterPythonScript()
{
	QVector<QString> res;
	QFile file("src/text.txt");
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream fileTxt(&file);
	QString jsonString = fileTxt.readAll();
	file.close();
	for (int i = 0, k = 0; i < jsonString.size(); i++) {
		if (jsonString[i] == '&') {
			res.append(jsonString.mid(k, i - k));
			k = i + 1;
		}
	}
	res.append(jsonString.right(1));

	return res;
}

