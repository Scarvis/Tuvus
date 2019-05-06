#ifndef DOCUMENTSLISTMODULE_H
#define DOCUMENTSLISTMODULE_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QImage>
#include <QBuffer>
#include <QUrl>

struct documentsListItem
{
    QString pathFile;
    QString nameFile;
};

class DocumentsListModule : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentPathFile READ getItem CONSTANT)
    Q_PROPERTY(QVector<int> statusDocument READ currentStatusDocument CONSTANT)
    Q_PROPERTY(QVector<int> recognizeQuestionsResults READ getRecognizeIssuesResults CONSTANT)
    Q_PROPERTY(QVector<int> rightAnswersArray READ getRightAnswersArray CONSTANT)
public:
    explicit DocumentsListModule(QObject *parent = nullptr);

    bool setItemAt(int index, const documentsListItem &item);

    QVector<documentsListItem> items() const;
    QString getItem(const int index);
    QVector<int> getCurrentStatusDocument() const;


    DocumentsListModule(const DocumentsListModule &documents) {
        mItems = documents.mItems;
        statusDocuments = documents.statusDocuments;
        recognizeQuestionsResult = documents.recognizeQuestionsResult;
        rightAnswersArray = documents.rightAnswersArray;
        mCurrentIndexClicked = documents.mCurrentIndexClicked;
    }
    DocumentsListModule operator=(const DocumentsListModule right){
        if(this == &right)
            return *this;
        mItems = right.mItems;
        statusDocuments = right.statusDocuments;
        recognizeQuestionsResult = right.recognizeQuestionsResult;
        rightAnswersArray = right.rightAnswersArray;
        mCurrentIndexClicked = right.mCurrentIndexClicked;
    }

signals:
    void preItemAppend();
    void postItemAppend();

public slots:
    void appendItem();
    int currentIndexClicked();
    void setIndexClicked(int indexClicked);
    QString getItem();
    QVector<int> currentStatusDocument() const;
    int getCurrentIndexClicked() const;
    QVector<int> getRecognizeIssuesResults() const;
    QVector <int> getRightAnswersArray() const;
    QString getCurrentCropQuestion(int index);

    void startRecognition();


private:
    QImage cropImage(QImage original, QRect rect);
    QVector<documentsListItem> mItems;
    int mCurrentIndexClicked = 0;
    QString currentPathFile = "Example_2-1.PNG";
    QVector<int> statusDocuments;
    QVector<int> recognizeQuestionsResult;
    QVector<int> rightAnswersArray;
    //QUrl m_fileUrl;
};

#endif // DOCUMENTSLISTMODULE_H
