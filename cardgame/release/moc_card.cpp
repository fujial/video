/****************************************************************************
** Meta object code from reading C++ file 'card.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../card.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'card.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_card_t {
    QByteArrayData data[20];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_card_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_card_t qt_meta_stringdata_card = {
    {
QT_MOC_LITERAL(0, 0, 4), // "card"
QT_MOC_LITERAL(1, 5, 14), // "sig_cardselect"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "sig_usecard"
QT_MOC_LITERAL(4, 33, 10), // "paintEvent"
QT_MOC_LITERAL(5, 44, 12), // "QPaintEvent*"
QT_MOC_LITERAL(6, 57, 5), // "event"
QT_MOC_LITERAL(7, 63, 15), // "mousePressEvent"
QT_MOC_LITERAL(8, 79, 12), // "QMouseEvent*"
QT_MOC_LITERAL(9, 92, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(10, 110, 14), // "set_cardATKnum"
QT_MOC_LITERAL(11, 125, 3), // "num"
QT_MOC_LITERAL(12, 129, 14), // "get_cardATKnum"
QT_MOC_LITERAL(13, 144, 12), // "set_cardInfo"
QT_MOC_LITERAL(14, 157, 3), // "ATK"
QT_MOC_LITERAL(15, 161, 4), // "LIFE"
QT_MOC_LITERAL(16, 166, 4), // "COST"
QT_MOC_LITERAL(17, 171, 7), // "user_id"
QT_MOC_LITERAL(18, 179, 13), // "set_cardOwner"
QT_MOC_LITERAL(19, 193, 2) // "id"

    },
    "card\0sig_cardselect\0\0sig_usecard\0"
    "paintEvent\0QPaintEvent*\0event\0"
    "mousePressEvent\0QMouseEvent*\0"
    "mouseReleaseEvent\0set_cardATKnum\0num\0"
    "get_cardATKnum\0set_cardInfo\0ATK\0LIFE\0"
    "COST\0user_id\0set_cardOwner\0id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_card[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   61,    2, 0x0a /* Public */,
       7,    1,   64,    2, 0x0a /* Public */,
       9,    1,   67,    2, 0x0a /* Public */,
      10,    1,   70,    2, 0x0a /* Public */,
      12,    0,   73,    2, 0x0a /* Public */,
      13,    4,   74,    2, 0x0a /* Public */,
      18,    1,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    6,
    QMetaType::Void, 0x80000000 | 8,    6,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::Int,   19,

       0        // eod
};

void card::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        card *_t = static_cast<card *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_cardselect(); break;
        case 1: _t->sig_usecard(); break;
        case 2: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 3: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->set_cardATKnum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: { int _r = _t->get_cardATKnum();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: _t->set_cardInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 8: _t->set_cardOwner((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (card::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&card::sig_cardselect)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (card::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&card::sig_usecard)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject card::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_card.data,
      qt_meta_data_card,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *card::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *card::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_card.stringdata0))
        return static_cast<void*>(const_cast< card*>(this));
    return QWidget::qt_metacast(_clname);
}

int card::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void card::sig_cardselect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void card::sig_usecard()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
