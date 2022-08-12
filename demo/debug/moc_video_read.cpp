/****************************************************************************
** Meta object code from reading C++ file 'video_read.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VideoApi/video_read.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'video_read.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_video_read_t {
    QByteArrayData data[11];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_video_read_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_video_read_t qt_meta_stringdata_video_read = {
    {
QT_MOC_LITERAL(0, 0, 10), // "video_read"
QT_MOC_LITERAL(1, 11, 13), // "SIG_videoShow"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "QImage&"
QT_MOC_LITERAL(4, 34, 3), // "img"
QT_MOC_LITERAL(5, 38, 13), // "SIG_videoDate"
QT_MOC_LITERAL(6, 52, 11), // "QByteArray&"
QT_MOC_LITERAL(7, 64, 8), // "byte_arr"
QT_MOC_LITERAL(8, 73, 16), // "slot_video_start"
QT_MOC_LITERAL(9, 90, 16), // "slot_video_pause"
QT_MOC_LITERAL(10, 107, 19) // "slot_video_readmore"

    },
    "video_read\0SIG_videoShow\0\0QImage&\0img\0"
    "SIG_videoDate\0QByteArray&\0byte_arr\0"
    "slot_video_start\0slot_video_pause\0"
    "slot_video_readmore"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_video_read[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   45,    2, 0x0a /* Public */,
       9,    0,   46,    2, 0x0a /* Public */,
      10,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void video_read::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        video_read *_t = static_cast<video_read *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_videoShow((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->SIG_videoDate((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->slot_video_start(); break;
        case 3: _t->slot_video_pause(); break;
        case 4: _t->slot_video_readmore(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (video_read::*_t)(QImage & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_read::SIG_videoShow)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (video_read::*_t)(QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_read::SIG_videoDate)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject video_read::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_video_read.data,
      qt_meta_data_video_read,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *video_read::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *video_read::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_video_read.stringdata0))
        return static_cast<void*>(const_cast< video_read*>(this));
    return QObject::qt_metacast(_clname);
}

int video_read::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void video_read::SIG_videoShow(QImage & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void video_read::SIG_videoDate(QByteArray & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
