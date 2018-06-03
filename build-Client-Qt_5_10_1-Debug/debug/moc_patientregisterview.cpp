/****************************************************************************
** Meta object code from reading C++ file 'patientregisterview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/patientregisterview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'patientregisterview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PatientRegisterView_t {
    QByteArrayData data[7];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PatientRegisterView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PatientRegisterView_t qt_meta_stringdata_PatientRegisterView = {
    {
QT_MOC_LITERAL(0, 0, 19), // "PatientRegisterView"
QT_MOC_LITERAL(1, 20, 18), // "on_confirm_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 9), // "getResult"
QT_MOC_LITERAL(4, 50, 19), // "QList<QVariantMap*>"
QT_MOC_LITERAL(5, 70, 15), // "getErrorMessage"
QT_MOC_LITERAL(6, 86, 15) // "getRightMessage"

    },
    "PatientRegisterView\0on_confirm_clicked\0"
    "\0getResult\0QList<QVariantMap*>\0"
    "getErrorMessage\0getRightMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PatientRegisterView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    1,   35,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PatientRegisterView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PatientRegisterView *_t = static_cast<PatientRegisterView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_confirm_clicked(); break;
        case 1: _t->getResult((*reinterpret_cast< QList<QVariantMap*>(*)>(_a[1]))); break;
        case 2: _t->getErrorMessage(); break;
        case 3: _t->getRightMessage(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PatientRegisterView::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PatientRegisterView.data,
      qt_meta_data_PatientRegisterView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PatientRegisterView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PatientRegisterView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PatientRegisterView.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int PatientRegisterView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
