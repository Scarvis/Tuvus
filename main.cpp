#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFontDatabase>
#include <QDebug>

#include "backend.h"
#include "documentslistmodel.h"
#include "documentslistmodule.h"
#include "patternrecognitionmodule.h"
//#include "imageprovider.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QFontDatabase fontDatabase;
    if (fontDatabase.addApplicationFont(":/fontello.ttf") == -1)
        qWarning() << "Failed to load fontello.ttf";

    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");
    qmlRegisterType<DocumentsListModel>("DocumentsList", 1, 0, "DocumentsListModel");
    qmlRegisterUncreatableType<DocumentsListModule>("DocumentsList", 1, 0, "DocumentsListModule",
                                                    QStringLiteral("should not be created in QML"));
    patternRecognitionModule patre();
    //qWarning() << "Dir: " << QDir::currentPath();
    DocumentsListModule documentsListFromDB;

    QQmlApplicationEngine engine;
//    ImageProvider *imgProvider = new ImageProvider();
//    engine.addImageProvider("provedor", imgProvider);

    engine.rootContext()->setContextProperty(QStringLiteral("documentsListFromDB"), &documentsListFromDB);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
