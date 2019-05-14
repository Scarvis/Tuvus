#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFontDatabase>
#include <QDebug>



#include "backend.h"
#include "documentslistmodel.h"
#include "documentslistmodule.h"
#include "inspectionsystem.h"
#include "patternrecognitionmodule.h"
#include "documenthandler.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QFontDatabase fontDatabase;
    if (fontDatabase.addApplicationFont(":/fontello.ttf") == -1)
        qWarning() << "Failed to load fontello.ttf";

    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");
    qmlRegisterType<DocumentsListModel>("DocumentsList", 1, 0, "DocumentsListModel");
    qmlRegisterType<DocumentHandler>("io.qt.docHandler", 1, 0, "DocumentHandler");
    qmlRegisterType<inspectionSystem>("DocumentsList", 1, 0, "QInspectionSystem");
    qmlRegisterUncreatableType<DocumentsListModule>("DocumentsList", 1, 0, "DocumentsListModule",
                                                    QStringLiteral("should not be created in QML"));


    

	DocumentsListModule documentsListFromDB;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty(QStringLiteral("documentsListFromDB"), &documentsListFromDB);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
