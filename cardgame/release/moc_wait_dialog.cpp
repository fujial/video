/****************************************************************************
** Meta object code from reading C++ file 'wait_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wait_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wait_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_wait_dialog_t {
    QByteArrayData data[9];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_wait_dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_wait_dialog_t qt_meta_stringdata_wait_dialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "wait_dialog"
QT_MOC_LITERAL(1, 12, 14), // "SIG_createroom"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "SIG_joinroom"
QT_MOC_LITERAL(4, 41, 9), // "SIG_close"
QT_MOC_LITERAL(5, 51, 10), // "SIG_return"
QT_MOC_LITERAL(6, 62, 22), // "on_pb_joinroom_clicked"
QT_MOC_LITERAL(7, 85, 24), // "on_pb_createroom_clicked"
QT_MOC_LITERAL(8, 110, 20) // "on_pb_return_clicked"

    },
    "wait_dialog\0SIG_createroom\0\0SIG_joinroom\0"
    "SIG_close\0SIG_return\0on_pb_joinroom_clicked\0"
    "on_pb_createroom_clicked\0on_pb_return_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wait_dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void wait_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        wait_dialog *_t = static_cast<wait_dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_createroom(); break;
        case 1: _t->SIG_joinroom(); break;
        case 2: _t->SIG_close(); break;
        case 3: _t->SIG_return(); break;
        case 4: _t->on_pb_joinroom_clicked(); break;
        case 5: _t->on_pb_createroom_clicked(); break;
        case 6: _t->on_pb_return_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (wait_dialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&wait_dialog::SIG_createroom)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (wait_dialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&wait_dialog::SIG_joinroom)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (wait_dialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&wait_dialog::SIG_close)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (wait_dialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&wait_dialog::SIG_return)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject wait_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_wait_dialog.data,
      qt_meta_data_wait_dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *wait_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wait_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_wait_dialog.stringdata0))
        return static_cast<void*>(const_cast< wait_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int wait_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void wait_dialog::SIG_createroom()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void wait_dialog::SIG_joinroom()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void wait_dialog::SIG_close()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void wait_dialog::SIG_return()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
