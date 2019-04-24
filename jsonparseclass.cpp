#include "jsonparseclass.h"

JsonParseClass::JsonParseClass()
{

}

InfoClass JsonParseClass::setTestData(QVariantMap qMap, QStringList keyList)
{
    InfoClass res;
    for (int j = 0; j < keyList.size(); j++) {
        QString key = keyList.at(j);
        for (int k = 0; k < keysJson.size(); k++) {
            if(key == keysJson[k]){
                switch (k) {
                case 0: res.setNumber(qMap[key.toLocal8Bit()].toInt());
                    break;
                case 1: res.setX(qMap[key.toLocal8Bit()].toInt());
                    break;
                case 2: res.setY(qMap[key.toLocal8Bit()].toInt());
                    break;
                case 3: res.setWidth(qMap[key.toLocal8Bit()].toInt());
                    break;
                case 4: res.setHeight(qMap[key.toLocal8Bit()].toInt());
                    break;
                }
            }
        }
    }
    return res;
}
