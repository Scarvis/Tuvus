/****************************************************************************
** Meta object code from reading C++ file 'documentslistmodule.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../documentslistmodule.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'documentslistmodule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DocumentsListModule_t {
    QByteArrayData data[21];
    char stringdata0[344];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DocumentsListModule_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DocumentsListModule_t qt_meta_stringdata_DocumentsListModule = {
    {
QT_MOC_LITERAL(0, 0, 19), // "DocumentsListModule"
QT_MOC_LITERAL(1, 20, 13), // "preItemAppend"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 14), // "postItemAppend"
QT_MOC_LITERAL(4, 50, 10), // "appendItem"
QT_MOC_LITERAL(5, 61, 19), // "currentIndexClicked"
QT_MOC_LITERAL(6, 81, 15), // "setIndexClicked"
QT_MOC_LITERAL(7, 97, 12), // "indexClicked"
QT_MOC_LITERAL(8, 110, 7), // "getItem"
QT_MOC_LITERAL(9, 118, 21), // "currentStatusDocument"
QT_MOC_LITERAL(10, 140, 12), // "QVector<int>"
QT_MOC_LITERAL(11, 153, 22), // "getCurrentIndexClicked"
QT_MOC_LITERAL(12, 176, 25), // "getRecognizeIssuesResults"
QT_MOC_LITERAL(13, 202, 20), // "getRightAnswersArray"
QT_MOC_LITERAL(14, 223, 22), // "getCurrentCropQuestion"
QT_MOC_LITERAL(15, 246, 5), // "index"
QT_MOC_LITERAL(16, 252, 16), // "startRecognition"
QT_MOC_LITERAL(17, 269, 15), // "currentPathFile"
QT_MOC_LITERAL(18, 285, 14), // "statusDocument"
QT_MOC_LITERAL(19, 300, 25), // "recognizeQuestionsResults"
QT_MOC_LITERAL(20, 326, 17) // "rightAnswersArray"

    },
    "DocumentsListModule\0preItemAppend\0\0"
    "postItemAppend\0appendItem\0currentIndexClicked\0"
    "setIndexClicked\0indexClicked\0getItem\0"
    "currentStatusDocument\0QVector<int>\0"
    "getCurrentIndexClicked\0getRecognizeIssuesResults\0"
    "getRightAnswersArray\0getCurrentCropQuestion\0"
    "index\0startRecognition\0currentPathFile\0"
    "statusDocument\0recognizeQuestionsResults\0"
    "rightAnswersArray"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DocumentsListModule[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       4,   90, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    1,   78,    2, 0x0a /* Public */,
       8,    0,   81,    2, 0x0a /* Public */,
       9,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,
      14,    1,   86,    2, 0x0a /* Public */,
      16,    0,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::QString,
    0x80000000 | 10,
    QMetaType::Int,
    0x80000000 | 10,
    0x80000000 | 10,
    QMetaType::QString, QMetaType::Int,   15,
    QMetaType::Void,

 // properties: name, type, flags
      17, QMetaType::QString, 0x00095401,
      18, 0x80000000 | 10, 0x00095409,
      19, 0x80000000 | 10, 0x00095409,
      20, 0x80000000 | 10, 0x00095409,

       0        // eod
};

void DocumentsListModule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DocumentsListModule *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->preItemAppend(); break;
        case 1: _t->postItemAppend(); break;
        case 2: _t->appendItem(); break;
        case 3: { int _r = _t->currentIndexClicked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->setIndexClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: { QString _r = _t->getItem();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVector<int> _r = _t->currentStatusDocument();
            if (_a[0]) *reinterpret_cast< QVector<int>*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->getCurrentIndexClicked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { QVector<int> _r = _t->getRecognizeIssuesResults();
            if (_a[0]) *reinterpret_cast< QVector<int>*>(_a[0]) = std::move(_r); }  break;
        case 9: { QVector<int> _r = _t->getRightAnswersArray();
            if (_a[0]) *reinterpret_cast< QVector<int>*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->getCurrentCropQuestion((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->startRecognition(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DocumentsListModule::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentsListModule::preItemAppend)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DocumentsListModule::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentsListModule::postItemAppend)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
        case 2:
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DocumentsListModule *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getItem(); break;
        case 1: *reinterpret_cast< QVector<int>*>(_v) = _t->currentStatusDocument(); break;
        case 2: *reinterpret_cast< QVector<int>*>(_v) = _t->getRecognizeIssuesResults(); break;
        case 3: *reinterpret_cast< QVector<int>*>(_v) = _t->getRightAnswersArray(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject DocumentsListModule::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DocumentsListModule.data,
    qt_meta_data_DocumentsListModule,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DocumentsListModule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DocumentsListModule::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DocumentsListModule.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DocumentsListModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DocumentsListModule::preItemAppend()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DocumentsListModule::postItemAppend()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
