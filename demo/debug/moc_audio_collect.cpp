/****************************************************************************
** Meta object code from reading C++ file 'audio_collect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AudioApi/audio_collect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audio_collect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Audio_collect_t {
    QByteArrayData data[7];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Audio_collect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Audio_collect_t qt_meta_stringdata_Audio_collect = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Audio_collect"
QT_MOC_LITERAL(1, 14, 14), // "SIG_audioFrame"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "QByteArray&"
QT_MOC_LITERAL(4, 42, 15), // "slot_audiostart"
QT_MOC_LITERAL(5, 58, 15), // "slot_audiopause"
QT_MOC_LITERAL(6, 74, 13) // "slot_timesend"

    },
    "Audio_collect\0SIG_audioFrame\0\0QByteArray&\0"
    "slot_audiostart\0slot_audiopause\0"
    "slot_timesend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Audio_collect[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   37,    2, 0x0a /* Public */,
       5,    0,   38,    2, 0x0a /* Public */,
       6,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Audio_collect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Audio_collect *_t = static_cast<Audio_collect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_audioFrame((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->slot_audiostart(); break;
        case 2: _t->slot_audiopause(); break;
        case 3: _t->slot_timesend(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Audio_collect::*_t)(QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Audio_collect::SIG_audioFrame)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Audio_collect::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Audio_collect.data,
      qt_meta_data_Audio_collect,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Audio_collect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Audio_collect::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Audio_collect.stringdata0))
        return static_cast<void*>(const_cast< Audio_collect*>(this));
    return QObject::qt_metacast(_clname);
}

int Audio_collect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Audio_collect::SIG_audioFrame(QByteArray & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
