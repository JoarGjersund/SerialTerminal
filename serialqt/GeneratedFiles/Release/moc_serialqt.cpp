/****************************************************************************
** Meta object code from reading C++ file 'serialqt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../serialqt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialqt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_serialqt_t {
    QByteArrayData data[11];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialqt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialqt_t qt_meta_stringdata_serialqt = {
    {
QT_MOC_LITERAL(0, 0, 8), // "serialqt"
QT_MOC_LITERAL(1, 9, 9), // "writeData"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "exitProgram"
QT_MOC_LITERAL(4, 32, 14), // "openSerialPort"
QT_MOC_LITERAL(5, 47, 8), // "portName"
QT_MOC_LITERAL(6, 56, 11), // "setBaudrate"
QT_MOC_LITERAL(7, 68, 8), // "baudrate"
QT_MOC_LITERAL(8, 77, 15), // "closeSerialPort"
QT_MOC_LITERAL(9, 93, 8), // "readData"
QT_MOC_LITERAL(10, 102, 6) // "update"

    },
    "serialqt\0writeData\0\0exitProgram\0"
    "openSerialPort\0portName\0setBaudrate\0"
    "baudrate\0closeSerialPort\0readData\0"
    "update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialqt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       6,    1,   54,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void serialqt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        serialqt *_t = static_cast<serialqt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->writeData(); break;
        case 1: _t->exitProgram(); break;
        case 2: _t->openSerialPort((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setBaudrate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->closeSerialPort(); break;
        case 5: _t->readData(); break;
        case 6: _t->update(); break;
        default: ;
        }
    }
}

const QMetaObject serialqt::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_serialqt.data,
      qt_meta_data_serialqt,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *serialqt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialqt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialqt.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int serialqt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
