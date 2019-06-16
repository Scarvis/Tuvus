#include "patternrecognitionmodule.h"


patternRecognitionModule::patternRecognitionModule()
{
	setNewPatternRecognition("test2");
	//generateRandomAnswers();
	setRightAnswers();
}

patternRecognitionModule::patternRecognitionModule(QString str)
{
    if(str == "test"){
        setTestPatternRecognition();


        //QJsonDocument document = QJsonDocument::fromJson()

    }
}

int patternRecognitionModule::setNewPatternRecognition(QString str)
{
    if(str == "test2"){
		const QDir test2 = patternsPath + "History.json";
		qDebug() << test2.path();
		QFile file(test2.path());
		file.open(QIODevice::ReadOnly | QIODevice::Text);
		QTextStream fileTxt(&file);
		QString jsonString = fileTxt.readAll();
		file.close();
		QByteArray jsonBytes = jsonString.toLocal8Bit();
		QJsonParseError jsonError;
		auto jsonDoc = QJsonDocument::fromJson(jsonBytes, &jsonError);
		if (jsonError.error != QJsonParseError::NoError) {
			qDebug() << jsonError.errorString() << jsonError.error;
			return -1;
		}

		if (jsonDoc.isNull()) {
			qDebug() << "Failed to create JSON doc.";
			return -2;
		}
		if (!jsonDoc.isObject()) {
			qDebug() << "JSON is not an object.";
			return -3;
		}

		QJsonObject jsonObj = jsonDoc.object();

		if (jsonObj.isEmpty()) {
			qDebug() << "JSON object is empty.";
			return -4;
		}
		

		QVariantMap jsonMapRoot = jsonObj.toVariantMap();
		countQuestion = jsonMapRoot["countQuestion"].toInt();
		numbersOfReplies = jsonMapRoot["numbersOfReplies"].toInt();
		defaultNumbersOfCorrectReplies = jsonMapRoot["defaultNumbersOfCorrectReplies"].toInt();
		indentBetweenQuestions = jsonMapRoot["indentBetweenQuestions"].toInt();
		recognitionArea.clear();
		QVariantList jsonList = jsonMapRoot["questions"].toList();
		for (int i = 0; i < jsonList.size(); i++) {
			QVariantMap jsonMap = jsonList[i].toMap();
			QStringList keyList = jsonMap.keys();
			InfoClass curInfo = jsonParse.setTestData(jsonMap, keyList);
			recognitionArea.append(curInfo);
		}
    }
    return 0;
}

int patternRecognitionModule::isOk() const
{
    return isOkCurrentPattern;
}

int patternRecognitionModule::setTestPatternRecognition()
{
    qDebug() << testPatternFilePath.path();
    QFile file(testPatternFilePath.path());
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream fileTxt(&file);
    QString jsonString = fileTxt.readAll();
    file.close();
    QByteArray jsonBytes = jsonString.toLocal8Bit();
    QJsonParseError jsonError;
    auto jsonDoc = QJsonDocument::fromJson(jsonBytes, &jsonError);
    if(jsonError.error != QJsonParseError::NoError){
        qDebug() << jsonError.errorString() << jsonError.error;
        exit(-1);
        //return -1;
    }


    if(jsonDoc.isNull()){
        qDebug()<<"Failed to create JSON doc.";
        exit(2);
    }
    if(!jsonDoc.isObject()){
        qDebug()<<"JSON is not an object.";
        exit(3);
    }

    QJsonObject jsonObj = jsonDoc.object();

    if(jsonObj.isEmpty()){
        qDebug()<<"JSON object is empty.";
        exit(4);
    }

    QVariantMap jsonMapRoot = jsonObj.toVariantMap();
    countQuestion = jsonMapRoot["countQuestion"].toInt();
    numbersOfReplies = jsonMapRoot["numbersOfReplies"].toInt();
    defaultNumbersOfCorrectReplies = jsonMapRoot["defaultNumbersOfCorrectReplies"].toInt();
    indentBetweenQuestions = jsonMapRoot["indentBetweenQuestions"].toInt();
    QVariantList jsonList = jsonMapRoot["questions"].toList();
    for (int i = 0; i < jsonList.size(); i++) {
        QVariantMap jsonMap = jsonList[i].toMap();
        QStringList keyList = jsonMap.keys();
        InfoClass curInfo = jsonParse.setTestData(jsonMap, keyList);
		curInfo.setQuest(1);
		recognitionArea.append(curInfo);
    }
	jsonList = jsonMapRoot["answers"].toList();
	for (int i = 0; i < jsonList.size(); i++) {
		QVariantMap jsonMap = jsonList[i].toMap();
		QStringList keyList = jsonMap.keys();
		InfoClass curInfo = jsonParse.setTestData(jsonMap, keyList);
		questionsAnswersInfo.append(curInfo);
	}
    
    //    jsonList.clear();
    //    jsonList = jsonMapRoot["answers"].toList();
    //    for (int i = 0; i < jsonList.size(); i++) {
    //        QVariantMap jsonMap = jsonList[i].toMap();
    //        QStringList keyList = jsonMap.keys();
    //        InfoClass curInfo = jsonParse().setTestData(jsonMap, keyList);
    //        questionsAnswersInfo.append(curInfo);
    //    }

//    QString fileName = QDir::currentPath() + "/src/patterns/data.txt";
//    QFile fileRes(fileName);
//    if(fileRes.open(QIODevice::ReadWrite)){
//        QTextStream stream(&fileRes);
//        stream << "countQuestion: " << countQuestion << "\n";
//        stream << "numbersOfReplies: " << numbersOfReplies << "\n";
//        stream << "defaultNumbersOfCorrectReplies: " << defaultNumbersOfCorrectReplies << "\n";
//        stream << "indentBetweenQuestions: " << indentBetweenQuestions << "\n";
//        stream << "questions: " << "\n";
//        for (int i = 0; i < questionsAnswersInfo.size(); i++) {
//            stream << questionsAnswersInfo[i].number() << " " << questionsAnswersInfo[i].x() << "\n";
//        }
//    }

    return 1;
}

int patternRecognitionModule::setRightAnswers()
{
	QFile jsonFile(answersFilesPath + "physics_answers.json");
	jsonFile.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream fileTxt(&jsonFile);
	QString jsonString = fileTxt.readAll();
	jsonFile.close();
	QByteArray jsonBytes = jsonString.toLocal8Bit();
	QJsonParseError jsonError;
	auto jsonDoc = QJsonDocument::fromJson(jsonBytes, &jsonError);
	if (jsonError.error != QJsonParseError::NoError) {
		qDebug() << jsonError.errorString() << jsonError.error;
		return -1;
	}
	if (jsonDoc.isNull()) {
		qDebug() << "Failed to create JSON doc.";
		return -2;
	}
	if (!jsonDoc.isObject()) {
		qDebug() << "JSON is not an object.";
		return -3;
	}

	QJsonObject jsonObj = jsonDoc.object();
	if (jsonObj.isEmpty()) {
		qDebug() << "JSON object is empty.";
		return -4;
	}
	listAnswers.clear();
	QVariantMap jsonMapRoot = jsonObj.toVariantMap();
	countQuestion = jsonMapRoot["countAnswers"].toInt();

	QVariantList jsonList = jsonMapRoot["answers"].toList();
	for (int i = 0; i < jsonList.size(); i++) {
		QVariantMap jsonMap = jsonList[i].toMap();
		QStringList keyList = jsonMap.keys();
		for (int ind = 0; ind < keyList.size(); ind++) {
			QString key = keyList.at(ind);
			if (key == "text") {
				listAnswers.append(jsonMap[key.toLocal8Bit()].toString());
			}
		}
	}

	return 0;
}

QVector<QString> patternRecognitionModule::getRightAnswersList() const
{
	return listAnswers;
}

QVector<InfoClass> patternRecognitionModule::getRecognitionArea() const
{
    return recognitionArea;
}

InfoClass patternRecognitionModule::getRecognitionAreaAt(int index) const
{
	if (index < 0 || index - 1 >= recognitionArea.size())
		return InfoClass();
	return recognitionArea[index];
}

QVector<InfoClass> patternRecognitionModule::getAnswerRecognitionArea() const
{
	return questionsAnswersInfo;
}

int patternRecognitionModule::getSizeRecognitionArea() const
{
	return recognitionArea.size();
}

QString patternRecognitionModule::getPatternsPath() const
{
	return patternsPath;
}

QString patternRecognitionModule::getAnswersFilesPath() const
{
	return answersFilesPath;
}

bool patternRecognitionModule::saveNewPatternRecognition(const QUrl &fileUrl, QVector<QString> x, QVector<QString> y, QVector<QString> width, QVector<QString> height)
{
	const QString filePath = fileUrl.toLocalFile();
	QFile jsonFile(filePath);
	if (!jsonFile.open(QIODevice::WriteOnly))
	{
		return false;
	}

	QJsonObject currentJsonObject;
	QJsonDocument jsonToWrite;
	currentJsonObject["countQuestion"] = x.size();
	currentJsonObject["numbersOfReplies"] = 1;
	currentJsonObject["defaultNumbersOfCorrectReplies"] = 1;
	currentJsonObject["indentBetweenQuestions"] = 1;
	QJsonArray jsonArray;
	for (int i = 0; i < x.size(); i++) {
		QJsonObject ns;
		ns["number"] = QJsonValue::fromVariant(i + 1);
		ns["x"] = QJsonValue::fromVariant(x[i]);
		ns["y"] = QJsonValue::fromVariant(y[i]);
		ns["width"] = QJsonValue::fromVariant(width[i]);
		ns["height"] = QJsonValue::fromVariant(height[i]);
		jsonArray.push_back(ns);
	}
	currentJsonObject["questions"] = jsonArray;
	jsonToWrite.setObject(currentJsonObject);

	jsonFile.write(jsonToWrite.toJson());
	//jsonFile.write(QJsonDocument(currentJsonObject).toJson(QJsonDocument::Indented));
	jsonFile.close();
	
	return true;
}

void patternRecognitionModule::generateRandomAnswers()
{
	//const QString filePath = answersFilesPath.toLocalFile();
	QFile jsonFile(answersFilesPath + "physics_answers.json");
	if (!jsonFile.open(QIODevice::WriteOnly))
	{
		return;
	}

	QJsonObject currentJsonObject;
	QJsonDocument jsonToWrite;
	currentJsonObject["countAnswers"] = 40;
	QJsonArray jsonArray;
	for (int i = 0; i < 40; i++) {
		QJsonObject ns;
		ns["number"] = QJsonValue::fromVariant(i + 1);
		ns["text"] = QJsonValue::fromVariant((qrand() % 9) + 1);
		jsonArray.push_back(ns);
	}
	currentJsonObject["answers"] = jsonArray;
	jsonToWrite.setObject(currentJsonObject);

	jsonFile.write(jsonToWrite.toJson());
	//jsonFile.write(QJsonDocument(currentJsonObject).toJson(QJsonDocument::Indented));
	jsonFile.close();

}
