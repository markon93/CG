/****************************************************************************
** Meta object code from reading C++ file 'ass3widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Part3/ass3widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ass3widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Ass3Widget_t {
    QByteArrayData data[83];
    char stringdata0[1476];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ass3Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ass3Widget_t qt_meta_stringdata_Ass3Widget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Ass3Widget"
QT_MOC_LITERAL(1, 11, 10), // "changeFile"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "std::string"
QT_MOC_LITERAL(4, 35, 8), // "filename"
QT_MOC_LITERAL(5, 44, 9), // "changeFOV"
QT_MOC_LITERAL(6, 54, 3), // "fov"
QT_MOC_LITERAL(7, 58, 10), // "changePFar"
QT_MOC_LITERAL(8, 69, 1), // "d"
QT_MOC_LITERAL(9, 71, 19), // "changeToPerspective"
QT_MOC_LITERAL(10, 91, 16), // "changeToParallel"
QT_MOC_LITERAL(11, 108, 14), // "changeOblScale"
QT_MOC_LITERAL(12, 123, 5), // "scale"
QT_MOC_LITERAL(13, 129, 14), // "changeOblAngle"
QT_MOC_LITERAL(14, 144, 5), // "angle"
QT_MOC_LITERAL(15, 150, 11), // "changePlTop"
QT_MOC_LITERAL(16, 162, 3), // "top"
QT_MOC_LITERAL(17, 166, 11), // "changePlFar"
QT_MOC_LITERAL(18, 178, 5), // "plFar"
QT_MOC_LITERAL(19, 184, 12), // "changeLightX"
QT_MOC_LITERAL(20, 197, 1), // "x"
QT_MOC_LITERAL(21, 199, 12), // "changeLightY"
QT_MOC_LITERAL(22, 212, 1), // "y"
QT_MOC_LITERAL(23, 214, 12), // "changeLightZ"
QT_MOC_LITERAL(24, 227, 1), // "z"
QT_MOC_LITERAL(25, 229, 21), // "changeLightLuminanceR"
QT_MOC_LITERAL(26, 251, 1), // "r"
QT_MOC_LITERAL(27, 253, 21), // "changeLightLuminanceG"
QT_MOC_LITERAL(28, 275, 1), // "g"
QT_MOC_LITERAL(29, 277, 21), // "changeLightLuminanceB"
QT_MOC_LITERAL(30, 299, 1), // "b"
QT_MOC_LITERAL(31, 301, 19), // "changeAmbientLightR"
QT_MOC_LITERAL(32, 321, 19), // "changeAmbientLightG"
QT_MOC_LITERAL(33, 341, 19), // "changeAmbientLightB"
QT_MOC_LITERAL(34, 361, 11), // "changeK_A_R"
QT_MOC_LITERAL(35, 373, 11), // "changeK_A_G"
QT_MOC_LITERAL(36, 385, 11), // "changeK_A_B"
QT_MOC_LITERAL(37, 397, 11), // "changeK_D_R"
QT_MOC_LITERAL(38, 409, 11), // "changeK_D_G"
QT_MOC_LITERAL(39, 421, 11), // "changeK_D_B"
QT_MOC_LITERAL(40, 433, 11), // "changeK_S_R"
QT_MOC_LITERAL(41, 445, 11), // "changeK_S_G"
QT_MOC_LITERAL(42, 457, 11), // "changeK_S_B"
QT_MOC_LITERAL(43, 469, 11), // "changeAlpha"
QT_MOC_LITERAL(44, 481, 5), // "phong"
QT_MOC_LITERAL(45, 487, 15), // "activateTexture"
QT_MOC_LITERAL(46, 503, 6), // "active"
QT_MOC_LITERAL(47, 510, 13), // "changeTexture"
QT_MOC_LITERAL(48, 524, 4), // "name"
QT_MOC_LITERAL(49, 529, 23), // "on_btn_parallel_clicked"
QT_MOC_LITERAL(50, 553, 26), // "on_btn_perspective_clicked"
QT_MOC_LITERAL(51, 580, 24), // "on_spin_top_valueChanged"
QT_MOC_LITERAL(52, 605, 26), // "on_spin_plfar_valueChanged"
QT_MOC_LITERAL(53, 632, 5), // "plfar"
QT_MOC_LITERAL(54, 638, 29), // "on_spin_oblscale_valueChanged"
QT_MOC_LITERAL(55, 668, 29), // "on_spin_oblangle_valueChanged"
QT_MOC_LITERAL(56, 698, 24), // "on_spin_fov_valueChanged"
QT_MOC_LITERAL(57, 723, 26), // "on_spin_pefar_valueChanged"
QT_MOC_LITERAL(58, 750, 5), // "pefar"
QT_MOC_LITERAL(59, 756, 20), // "on_push_file_clicked"
QT_MOC_LITERAL(60, 777, 26), // "on_sb_light_x_valueChanged"
QT_MOC_LITERAL(61, 804, 26), // "on_sb_light_y_valueChanged"
QT_MOC_LITERAL(62, 831, 26), // "on_sb_light_z_valueChanged"
QT_MOC_LITERAL(63, 858, 32), // "on_sb_light_r_doubleValueChanged"
QT_MOC_LITERAL(64, 891, 1), // "v"
QT_MOC_LITERAL(65, 893, 32), // "on_sb_light_g_doubleValueChanged"
QT_MOC_LITERAL(66, 926, 32), // "on_sb_light_b_doubleValueChanged"
QT_MOC_LITERAL(67, 959, 34), // "on_sb_ambient_r_doubleValueCh..."
QT_MOC_LITERAL(68, 994, 34), // "on_sb_ambient_g_doubleValueCh..."
QT_MOC_LITERAL(69, 1029, 34), // "on_sb_ambient_b_doubleValueCh..."
QT_MOC_LITERAL(70, 1064, 36), // "on_sb_ambient_c_r_doubleValue..."
QT_MOC_LITERAL(71, 1101, 36), // "on_sb_ambient_c_g_doubleValue..."
QT_MOC_LITERAL(72, 1138, 36), // "on_sb_ambient_c_b_doubleValue..."
QT_MOC_LITERAL(73, 1175, 34), // "on_sb_diffuse_r_doubleValueCh..."
QT_MOC_LITERAL(74, 1210, 34), // "on_sb_diffuse_g_doubleValueCh..."
QT_MOC_LITERAL(75, 1245, 34), // "on_sb_diffuse_b_doubleValueCh..."
QT_MOC_LITERAL(76, 1280, 35), // "on_sb_specular_r_doubleValueC..."
QT_MOC_LITERAL(77, 1316, 35), // "on_sb_specular_g_doubleValueC..."
QT_MOC_LITERAL(78, 1352, 35), // "on_sb_specular_b_doubleValueC..."
QT_MOC_LITERAL(79, 1388, 24), // "on_sb_phong_valueChanged"
QT_MOC_LITERAL(80, 1413, 27), // "on_push_texturefile_clicked"
QT_MOC_LITERAL(81, 1441, 26), // "on_cb_show_texture_toggled"
QT_MOC_LITERAL(82, 1468, 7) // "checked"

    },
    "Ass3Widget\0changeFile\0\0std::string\0"
    "filename\0changeFOV\0fov\0changePFar\0d\0"
    "changeToPerspective\0changeToParallel\0"
    "changeOblScale\0scale\0changeOblAngle\0"
    "angle\0changePlTop\0top\0changePlFar\0"
    "plFar\0changeLightX\0x\0changeLightY\0y\0"
    "changeLightZ\0z\0changeLightLuminanceR\0"
    "r\0changeLightLuminanceG\0g\0"
    "changeLightLuminanceB\0b\0changeAmbientLightR\0"
    "changeAmbientLightG\0changeAmbientLightB\0"
    "changeK_A_R\0changeK_A_G\0changeK_A_B\0"
    "changeK_D_R\0changeK_D_G\0changeK_D_B\0"
    "changeK_S_R\0changeK_S_G\0changeK_S_B\0"
    "changeAlpha\0phong\0activateTexture\0"
    "active\0changeTexture\0name\0"
    "on_btn_parallel_clicked\0"
    "on_btn_perspective_clicked\0"
    "on_spin_top_valueChanged\0"
    "on_spin_plfar_valueChanged\0plfar\0"
    "on_spin_oblscale_valueChanged\0"
    "on_spin_oblangle_valueChanged\0"
    "on_spin_fov_valueChanged\0"
    "on_spin_pefar_valueChanged\0pefar\0"
    "on_push_file_clicked\0on_sb_light_x_valueChanged\0"
    "on_sb_light_y_valueChanged\0"
    "on_sb_light_z_valueChanged\0"
    "on_sb_light_r_doubleValueChanged\0v\0"
    "on_sb_light_g_doubleValueChanged\0"
    "on_sb_light_b_doubleValueChanged\0"
    "on_sb_ambient_r_doubleValueChanged\0"
    "on_sb_ambient_g_doubleValueChanged\0"
    "on_sb_ambient_b_doubleValueChanged\0"
    "on_sb_ambient_c_r_doubleValueChanged\0"
    "on_sb_ambient_c_g_doubleValueChanged\0"
    "on_sb_ambient_c_b_doubleValueChanged\0"
    "on_sb_diffuse_r_doubleValueChanged\0"
    "on_sb_diffuse_g_doubleValueChanged\0"
    "on_sb_diffuse_b_doubleValueChanged\0"
    "on_sb_specular_r_doubleValueChanged\0"
    "on_sb_specular_g_doubleValueChanged\0"
    "on_sb_specular_b_doubleValueChanged\0"
    "on_sb_phong_valueChanged\0"
    "on_push_texturefile_clicked\0"
    "on_cb_show_texture_toggled\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ass3Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      60,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      30,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  314,    2, 0x06 /* Public */,
       5,    1,  317,    2, 0x06 /* Public */,
       7,    1,  320,    2, 0x06 /* Public */,
       9,    0,  323,    2, 0x06 /* Public */,
      10,    0,  324,    2, 0x06 /* Public */,
      11,    1,  325,    2, 0x06 /* Public */,
      13,    1,  328,    2, 0x06 /* Public */,
      15,    1,  331,    2, 0x06 /* Public */,
      17,    1,  334,    2, 0x06 /* Public */,
      19,    1,  337,    2, 0x06 /* Public */,
      21,    1,  340,    2, 0x06 /* Public */,
      23,    1,  343,    2, 0x06 /* Public */,
      25,    1,  346,    2, 0x06 /* Public */,
      27,    1,  349,    2, 0x06 /* Public */,
      29,    1,  352,    2, 0x06 /* Public */,
      31,    1,  355,    2, 0x06 /* Public */,
      32,    1,  358,    2, 0x06 /* Public */,
      33,    1,  361,    2, 0x06 /* Public */,
      34,    1,  364,    2, 0x06 /* Public */,
      35,    1,  367,    2, 0x06 /* Public */,
      36,    1,  370,    2, 0x06 /* Public */,
      37,    1,  373,    2, 0x06 /* Public */,
      38,    1,  376,    2, 0x06 /* Public */,
      39,    1,  379,    2, 0x06 /* Public */,
      40,    1,  382,    2, 0x06 /* Public */,
      41,    1,  385,    2, 0x06 /* Public */,
      42,    1,  388,    2, 0x06 /* Public */,
      43,    1,  391,    2, 0x06 /* Public */,
      45,    1,  394,    2, 0x06 /* Public */,
      47,    1,  397,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      49,    0,  400,    2, 0x08 /* Private */,
      50,    0,  401,    2, 0x08 /* Private */,
      51,    1,  402,    2, 0x08 /* Private */,
      52,    1,  405,    2, 0x08 /* Private */,
      54,    1,  408,    2, 0x08 /* Private */,
      55,    1,  411,    2, 0x08 /* Private */,
      56,    1,  414,    2, 0x08 /* Private */,
      57,    1,  417,    2, 0x08 /* Private */,
      59,    0,  420,    2, 0x08 /* Private */,
      60,    1,  421,    2, 0x08 /* Private */,
      61,    1,  424,    2, 0x08 /* Private */,
      62,    1,  427,    2, 0x08 /* Private */,
      63,    1,  430,    2, 0x08 /* Private */,
      65,    1,  433,    2, 0x08 /* Private */,
      66,    1,  436,    2, 0x08 /* Private */,
      67,    1,  439,    2, 0x08 /* Private */,
      68,    1,  442,    2, 0x08 /* Private */,
      69,    1,  445,    2, 0x08 /* Private */,
      70,    1,  448,    2, 0x08 /* Private */,
      71,    1,  451,    2, 0x08 /* Private */,
      72,    1,  454,    2, 0x08 /* Private */,
      73,    1,  457,    2, 0x08 /* Private */,
      74,    1,  460,    2, 0x08 /* Private */,
      75,    1,  463,    2, 0x08 /* Private */,
      76,    1,  466,    2, 0x08 /* Private */,
      77,    1,  469,    2, 0x08 /* Private */,
      78,    1,  472,    2, 0x08 /* Private */,
      79,    1,  475,    2, 0x08 /* Private */,
      80,    0,  478,    2, 0x08 /* Private */,
      81,    1,  479,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Float,   20,
    QMetaType::Void, QMetaType::Float,   22,
    QMetaType::Void, QMetaType::Float,   24,
    QMetaType::Void, QMetaType::Double,   26,
    QMetaType::Void, QMetaType::Double,   28,
    QMetaType::Void, QMetaType::Double,   30,
    QMetaType::Void, QMetaType::Double,   26,
    QMetaType::Void, QMetaType::Double,   28,
    QMetaType::Void, QMetaType::Double,   30,
    QMetaType::Void, QMetaType::Double,   26,
    QMetaType::Void, QMetaType::Double,   28,
    QMetaType::Void, QMetaType::Double,   30,
    QMetaType::Void, QMetaType::Double,   26,
    QMetaType::Void, QMetaType::Double,   28,
    QMetaType::Void, QMetaType::Double,   30,
    QMetaType::Void, QMetaType::Double,   26,
    QMetaType::Void, QMetaType::Double,   28,
    QMetaType::Void, QMetaType::Double,   30,
    QMetaType::Void, QMetaType::Int,   44,
    QMetaType::Void, QMetaType::Bool,   46,
    QMetaType::Void, 0x80000000 | 3,   48,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Int,   53,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,   58,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   20,
    QMetaType::Void, QMetaType::Double,   22,
    QMetaType::Void, QMetaType::Double,   24,
    QMetaType::Void, QMetaType::Double,   64,
    QMetaType::Void, QMetaType::Double,   64,
    QMetaType::Void, QMetaType::Double,   64,
    QMetaType::Void, QMetaType::Double,   64,
    QMetaType::Void, QMetaType::Double,   64,
    QMetaType::Void, QMetaType::Double,   64,
    QMetaType::Void, QMetaType::Double,   64,
    QMetaType::Void, QMetaType::Double,   64,
    QMetaType::Void, QMetaType::Double,   64,
    QMetaType::Void, QMetaType::Double,   64,
    QMetaType::Void, QMetaType::Double,   64,
    QMetaType::Void, QMetaType::Double,   64,
    QMetaType::Void, QMetaType::Double,   64,
    QMetaType::Void, QMetaType::Double,   64,
    QMetaType::Void, QMetaType::Double,   64,
    QMetaType::Void, QMetaType::Int,   44,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   82,

       0        // eod
};

void Ass3Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ass3Widget *_t = static_cast<Ass3Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeFile((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->changeFOV((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changePFar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changeToPerspective(); break;
        case 4: _t->changeToParallel(); break;
        case 5: _t->changeOblScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->changeOblAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->changePlTop((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->changePlFar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->changeLightX((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 10: _t->changeLightY((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 11: _t->changeLightZ((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 12: _t->changeLightLuminanceR((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->changeLightLuminanceG((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->changeLightLuminanceB((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->changeAmbientLightR((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->changeAmbientLightG((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->changeAmbientLightB((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->changeK_A_R((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: _t->changeK_A_G((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->changeK_A_B((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: _t->changeK_D_R((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 22: _t->changeK_D_G((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 23: _t->changeK_D_B((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 24: _t->changeK_S_R((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 25: _t->changeK_S_G((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 26: _t->changeK_S_B((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 27: _t->changeAlpha((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->activateTexture((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->changeTexture((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 30: _t->on_btn_parallel_clicked(); break;
        case 31: _t->on_btn_perspective_clicked(); break;
        case 32: _t->on_spin_top_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 33: _t->on_spin_plfar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->on_spin_oblscale_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 35: _t->on_spin_oblangle_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 36: _t->on_spin_fov_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->on_spin_pefar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->on_push_file_clicked(); break;
        case 39: _t->on_sb_light_x_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 40: _t->on_sb_light_y_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 41: _t->on_sb_light_z_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 42: _t->on_sb_light_r_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 43: _t->on_sb_light_g_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 44: _t->on_sb_light_b_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 45: _t->on_sb_ambient_r_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 46: _t->on_sb_ambient_g_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 47: _t->on_sb_ambient_b_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 48: _t->on_sb_ambient_c_r_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 49: _t->on_sb_ambient_c_g_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 50: _t->on_sb_ambient_c_b_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 51: _t->on_sb_diffuse_r_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 52: _t->on_sb_diffuse_g_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 53: _t->on_sb_diffuse_b_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 54: _t->on_sb_specular_r_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 55: _t->on_sb_specular_g_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 56: _t->on_sb_specular_b_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 57: _t->on_sb_phong_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 58: _t->on_push_texturefile_clicked(); break;
        case 59: _t->on_cb_show_texture_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Ass3Widget::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeFile)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeFOV)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changePFar)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeToPerspective)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeToParallel)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeOblScale)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeOblAngle)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changePlTop)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changePlFar)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeLightX)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeLightY)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeLightZ)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeLightLuminanceR)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeLightLuminanceG)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeLightLuminanceB)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeAmbientLightR)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeAmbientLightG)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeAmbientLightB)) {
                *result = 17;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeK_A_R)) {
                *result = 18;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeK_A_G)) {
                *result = 19;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeK_A_B)) {
                *result = 20;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeK_D_R)) {
                *result = 21;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeK_D_G)) {
                *result = 22;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeK_D_B)) {
                *result = 23;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeK_S_R)) {
                *result = 24;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeK_S_G)) {
                *result = 25;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeK_S_B)) {
                *result = 26;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeAlpha)) {
                *result = 27;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::activateTexture)) {
                *result = 28;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeTexture)) {
                *result = 29;
                return;
            }
        }
    }
}

const QMetaObject Ass3Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Ass3Widget.data,
      qt_meta_data_Ass3Widget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Ass3Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ass3Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Ass3Widget.stringdata0))
        return static_cast<void*>(const_cast< Ass3Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Ass3Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 60)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 60;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 60)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 60;
    }
    return _id;
}

// SIGNAL 0
void Ass3Widget::changeFile(std::string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Ass3Widget::changeFOV(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Ass3Widget::changePFar(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Ass3Widget::changeToPerspective()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Ass3Widget::changeToParallel()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void Ass3Widget::changeOblScale(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Ass3Widget::changeOblAngle(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Ass3Widget::changePlTop(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Ass3Widget::changePlFar(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Ass3Widget::changeLightX(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Ass3Widget::changeLightY(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Ass3Widget::changeLightZ(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Ass3Widget::changeLightLuminanceR(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Ass3Widget::changeLightLuminanceG(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Ass3Widget::changeLightLuminanceB(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Ass3Widget::changeAmbientLightR(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Ass3Widget::changeAmbientLightG(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Ass3Widget::changeAmbientLightB(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void Ass3Widget::changeK_A_R(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void Ass3Widget::changeK_A_G(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void Ass3Widget::changeK_A_B(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void Ass3Widget::changeK_D_R(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void Ass3Widget::changeK_D_G(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void Ass3Widget::changeK_D_B(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void Ass3Widget::changeK_S_R(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void Ass3Widget::changeK_S_G(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void Ass3Widget::changeK_S_B(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void Ass3Widget::changeAlpha(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void Ass3Widget::activateTexture(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void Ass3Widget::changeTexture(std::string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}
QT_END_MOC_NAMESPACE
