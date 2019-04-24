#ifndef DOCUMENTHANDLER_H
#define DOCUMENTHANDLER_H

#include <QObject>
#include <QUrl>

class DocumentHandler : public QObject
{
public:
    DocumentHandler();
public Q_SLOTS:
    void load(const QUrl &fileUrl);

private:
    QUrl m_fileUrl;
};

#endif // DOCUMENTHANDLER_H
