#ifndef JSONPARSECLASS_H
#define JSONPARSECLASS_H
#include "infoclass.h"
#include <QVariantMap>

class JsonParseClass
{
public:
    JsonParseClass();
    InfoClass setTestData(QVariantMap qMap, QStringList keyList);
private:
    InfoClass infoData;
    const QStringList keysJson = {
          "number"
        , "x"
        , "y"
        , "width"
        , "height"
                           };
};

#endif // JSONPARSECLASS_H
