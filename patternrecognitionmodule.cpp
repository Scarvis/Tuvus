#include "patternrecognitionmodule.h"


patternRecognitionModule::patternRecognitionModule()
{

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
    if(str == "test"){
        isOkCurrentPattern = setTestPatternRecognition();
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
        questionsAnswersInfo.append(curInfo);
    }
    recognitionArea.append(InfoClass(190, 120, 75, 19));
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

QVector<InfoClass> patternRecognitionModule::getRecognitionArea()
{
    return recognitionArea;
}
