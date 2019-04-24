#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

//#include <QObject>
//#include <QQuickImageProvider>
//#include <QPainter>
//#include <QQmlExtensionPlugin>

//class ImageProvider : public QQuickImageProvider
//{
//    Q_OBJECT
//public:
//    ImageProvider();
//    //explicit ImageProvider(QObject *parent = nullptr);

//    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override
//    {
//        int width = 100;
//        int height = 50;

//        if (size)
//            *size = QSize(width, height);
//        QPixmap pixmap(requestedSize.width() > 0 ? requestedSize.width() : width,
//                       requestedSize.height() > 0 ? requestedSize.height() : height);
//        pixmap.fill(QColor(id).rgba());

//        // write the color name
////        QPainter painter(&pixmap);
////        QFont f = painter.font();
////        f.setPixelSize(20);
////        painter.setFont(f);
////        painter.setPen(Qt::black);
////        if (requestedSize.isValid())
////            painter.scale(requestedSize.width() / width, requestedSize.height() / height);
////        painter.drawText(QRectF(0, 0, width, height), Qt::AlignCenter, id);

//        return pixmap;
//    }


//signals:

//public slots:
//    //virtual QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);

//};

//class ImageProviderExtensionPlugin : public QQmlExtensionPlugin
//{
//    Q_OBJECT
//    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)
//public:
//    void registerTypes(const char *uri) override
//    {
//        Q_UNUSED(uri);
//    }

//    void initializeEngine(QQmlEngine *engine, const char *uri) override
//    {
//        Q_UNUSED(uri);
//        engine->addImageProvider("provedor", new ImageProvider);
//    }

//};

#endif // IMAGEPROVIDER_H
