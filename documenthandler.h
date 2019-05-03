#ifndef DOCUMENTHANDLER_H
#define DOCUMENTHANDLER_H

#include <QObject>
#include <QUrl>

class DocumentHandler : public QObject
{
public:
    DocumentHandler();

    void load(const QUrl &fileUrl);
    void loadFile(const QUrl &fileUrl);
    void loadFolder(const QUrl &folderUrl);

private:
    QUrl m_fileUrl;
};

#endif // DOCUMENTHANDLER_H
