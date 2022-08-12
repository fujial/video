/****************************************************************************
** Meta object code from reading C++ file 'my_usershow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../my_usershow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'my_usershow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_my_usershow_t {
    QByteArrayData data[15];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_my_usershow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_my_usershow_t qt_meta_stringdata_my_usershow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "my_usershow"
QT_MOC_LITERAL(1, 12, 15), // "SIG_userClicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "my_id"
QT_MOC_LITERAL(4, 35, 7), // "my_name"
QT_MOC_LITERAL(5, 43, 13), // "slot_setImage"
QT_MOC_LITERAL(6, 57, 5), // "image"
QT_MOC_LITERAL(7, 63, 12), // "slot_setInfo"
QT_MOC_LITERAL(8, 76, 2), // "id"
QT_MOC_LITERAL(9, 79, 4), // "name"
QT_MOC_LITERAL(10, 84, 10), // "paintEvent"
QT_MOC_LITERAL(11, 95, 12), // "QPaintEvent*"
QT_MOC_LITERAL(12, 108, 5), // "event"
QT_MOC_LITERAL(13, 114, 15), // "mousePressEvent"
QT_MOC_LITERAL(14, 130, 12) // "QMouseEvent*"

    },
    "my_usershow\0SIG_userClicked\0\0my_id\0"
    "my_name\0slot_setImage\0image\0slot_setInfo\0"
    "id\0name\0paintEvent\0QPaintEvent*\0event\0"
    "mousePressEvent\0QMouseEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_my_usershow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   44,    2, 0x0a /* Public */,
       7,    2,   47,    2, 0x0a /* Public */,
      10,    1,   52,    2, 0x0a /* Public */,
      13,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   12,

       0        // eod
};

void my_usershow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        my_usershow *_t = static_cast<my_usershow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_userClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->slot_setImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->slot_setInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 4: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (my_usershow::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&my_usershow::SIG_userClicked)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject my_usershow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_my_usershow.data,
      qt_meta_data_my_usershow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *my_usershow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *my_usershow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_my_usershow.stringdata0))
        return static_cast<void*>(const_cast< my_usershow*>(this));
    return QWidget::qt_metacast(_clname);
}

int my_usershow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void my_usershow::SIG_userClicked(int _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
