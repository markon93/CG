/****************************************************************************
** Meta object code from reading C++ file 'geometryrender.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Part3/geometryrender.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'geometryrender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GeometryRender_t {
    QByteArrayData data[19];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GeometryRender_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GeometryRender_t qt_meta_stringdata_GeometryRender = {
    {
QT_MOC_LITERAL(0, 0, 14), // "GeometryRender"
QT_MOC_LITERAL(1, 15, 9), // "changeFOV"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "fov"
QT_MOC_LITERAL(4, 30, 10), // "changePFar"
QT_MOC_LITERAL(5, 41, 1), // "d"
QT_MOC_LITERAL(6, 43, 12), // "getNewObject"
QT_MOC_LITERAL(7, 56, 11), // "std::string"
QT_MOC_LITERAL(8, 68, 8), // "filename"
QT_MOC_LITERAL(9, 77, 19), // "changeToPerspective"
QT_MOC_LITERAL(10, 97, 16), // "changeToParallel"
QT_MOC_LITERAL(11, 114, 14), // "changeOblScale"
QT_MOC_LITERAL(12, 129, 5), // "scale"
QT_MOC_LITERAL(13, 135, 14), // "changeOblAngle"
QT_MOC_LITERAL(14, 150, 5), // "angle"
QT_MOC_LITERAL(15, 156, 11), // "changePlTop"
QT_MOC_LITERAL(16, 168, 3), // "top"
QT_MOC_LITERAL(17, 172, 11), // "changePlFar"
QT_MOC_LITERAL(18, 184, 5) // "plfar"

    },
    "GeometryRender\0changeFOV\0\0fov\0changePFar\0"
    "d\0getNewObject\0std::string\0filename\0"
    "changeToPerspective\0changeToParallel\0"
    "changeOblScale\0scale\0changeOblAngle\0"
    "angle\0changePlTop\0top\0changePlFar\0"
    "plfar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeometryRender[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    1,   62,    2, 0x0a /* Public */,
       6,    1,   65,    2, 0x0a /* Public */,
       9,    0,   68,    2, 0x0a /* Public */,
      10,    0,   69,    2, 0x0a /* Public */,
      11,    1,   70,    2, 0x0a /* Public */,
      13,    1,   73,    2, 0x0a /* Public */,
      15,    1,   76,    2, 0x0a /* Public */,
      17,    1,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void GeometryRender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GeometryRender *_t = static_cast<GeometryRender *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeFOV((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changePFar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->getNewObject((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->changeToPerspective(); break;
        case 4: _t->changeToParallel(); break;
        case 5: _t->changeOblScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->changeOblAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->changePlTop((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->changePlFar((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GeometryRender::staticMetaObject = {
    { &OpenGLWindow::staticMetaObject, qt_meta_stringdata_GeometryRender.data,
      qt_meta_data_GeometryRender,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GeometryRender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeometryRender::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GeometryRender.stringdata0))
        return static_cast<void*>(const_cast< GeometryRender*>(this));
    return OpenGLWindow::qt_metacast(_clname);
}

int GeometryRender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = OpenGLWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
