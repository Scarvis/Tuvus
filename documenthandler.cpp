#include "documenthandler.h"
#include "documentslistmodule.h"
#include <QFile>
#include <QFileInfo>
#include <QFileSelector>
#include <QQmlFile>
#include <QQmlFileSelector>
#include <QQuickTextDocument>
#include <QTextCharFormat>
#include <QTextCodec>
#include <QTextDocument>
#include <QDebug>


DocumentHandler::DocumentHandler()
{

}

void DocumentHandler::load(const QUrl &fileUrl)
{
    if (fileUrl == m_fileUrl)
        return;

    QQmlEngine *engine = qmlEngine(this);
    if (!engine) {
        qWarning() << "load() called before DocumentHandler has QQmlEngine";
        return;
    }
    const QUrl path = QQmlFileSelector::get(engine)->selector()->select(fileUrl);
    const QString fileName = QQmlFile::urlToLocalFileOrQrc(path);
    if (QFile::exists(fileName)) {
       qDebug() << fileName << " " << path;
    }

    m_fileUrl = fileUrl;
    //emit fileUrlChanged();
}

void DocumentHandler::loadFile(const QUrl &fileUrl)
{
    QQmlEngine *engine = qmlEngine(this);
    if (!engine) {
        qWarning() << "load() called before DocumentHandler has QQmlEngine";
        return;
    }
    const QUrl path = QQmlFileSelector::get(engine)->selector()->select(fileUrl);
    const QString fileName = QQmlFile::urlToLocalFileOrQrc(path);
    if (!QFile::exists(fileName)) {
       qWarning() << "dont exists filename: " << fileName << " . path: " << path;
    }

    m_fileUrl = fileUrl;
}

void DocumentHandler::loadFolder(const QUrl &folderUrl)
{

}

