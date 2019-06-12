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
public:
    inspectionSystem();
    inspectionSystem(QString str);
    int recognition(patternRecognitionModule pattern);

public Q_SLOTS:
    void loadFile(const QUrl &fileUrl);
    void loadFolder(const QUrl &folderUrl);
    void recognizeCurrentFile();
	void recognizeSymbolsWithPython();
    void recognizeCurrentFolder();
    QString getPathFile(const int index);
    QVector<int> getCurrentStatusDocument() const;
	QVector<QString> getRightAnswersList() const;
	QVector<QString> getRecognizedIssuesList() const;
	QString getCurrentCloseUpDocumentRecognizeResult(int index) const;
	bool setDocumentsList(QVector<QString> mItems, int currentIndexClicked);
	int getMaxIndexCroppedQuestionImage() const;
	QString getCurrentCropQuestion(int index); //QML
	QString getCropImage(QString pathFile, QString x, QString y, QString width, QString height);
	QString getCurrentDocumentName() const;
	QVector<QString> getArrayPatternRecognition() const;
	QVector<QString> getArrayFileAnswers() const;

	bool savePatternRecognition(const QUrl &fileUrl, QVector<QString> x, QVector<QString> y, QVector<QString> width, QVector<QString> height);
	void saveImageCrop();
	bool setPatternRecognition();
private:
    patternRecognitionModule patternRecModule;
    RecognitionModule recognitionModule;
    DocumentHandler documentHandler;
    DocumentsListModule documentsListModule;

	QString checkPathFileForFile(QString pathFile);
	QVector<QString> parseTextFileAfterPythonScript();

    QVector<RecognitionResults> currentRecognitionResults;
	QVector<QString> currentRecognizedIssues;
	QVector<QString> currentRightAnswers;
    QUrl currentFileUrl;
    QUrl currentFolderUrl;
    QUrl lastRecognitionFolder = QUrl::fromLocalFile("21.PNG");
    QUrl lastRecognitionFile;
	QImage currentRecognitionDocument;
    int testP = 0;
	int maxIndexCroppedQuestionImage = 1;
	int currentIndexDocumentInQueue = 0;
	double recognitionPercentage = 0.0;
	int countRightAnswer = 0;
};

#endif // INSPECTIONSYSTEM_H
