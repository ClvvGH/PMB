/****************************************************************************
** Meta object code from reading C++ file 'selfinfoview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/selfinfoview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selfinfoview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SelfInfoView_t {
    QByteArrayData data[11];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelfInfoView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelfInfoView_t qt_meta_stringdata_SelfInfoView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SelfInfoView"
QT_MOC_LITERAL(1, 13, 6), // "logout"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 16), // "getAndShowResult"
QT_MOC_LITERAL(4, 38, 19), // "QList<QVariantMap*>"
QT_MOC_LITERAL(5, 58, 15), // "getRightMessage"
QT_MOC_LITERAL(6, 74, 15), // "getErrorMessage"
QT_MOC_LITERAL(7, 90, 21), // "on_backButton_clicked"
QT_MOC_LITERAL(8, 112, 23), // "on_logoutButton_clicked"
QT_MOC_LITERAL(9, 136, 25), // "on_securityButton_clicked"
QT_MOC_LITERAL(10, 162, 25) // "on_editInfoButton_clicked"

    },
    "SelfInfoView\0logout\0\0getAndShowResult\0"
    "QList<QVariantMap*>\0getRightMessage\0"
    "getErrorMessage\0on_backButton_clicked\0"
    "on_logoutButton_clicked\0"
    "on_securityButton_clicked\0"
    "on_editInfoButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelfInfoView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   55,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SelfInfoView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SelfInfoView *_t = static_cast<SelfInfoView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->logout(); break;
        case 1: _t->getAndShowResult((*reinterpret_cast< QList<QVariantMap*>(*)>(_a[1]))); break;
        case 2: _t->getRightMessage(); break;
        case 3: _t->getErrorMessage(); break;
        case 4: _t->on_backButton_clicked(); break;
        case 5: _t->on_logoutButton_clicked(); break;
        case 6: _t->on_securityButton_clicked(); break;
        case 7: _t->on_editInfoButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SelfInfoView::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SelfInfoView::logout)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SelfInfoView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SelfInfoView.data,
      qt_meta_data_SelfInfoView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SelfInfoView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelfInfoView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SelfInfoView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SelfInfoView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SelfInfoView::logout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
