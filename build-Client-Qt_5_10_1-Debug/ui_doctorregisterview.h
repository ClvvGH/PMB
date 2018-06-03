/********************************************************************************
** Form generated from reading UI file 'doctorregisterview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORREGISTERVIEW_H
#define UI_DOCTORREGISTERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_DoctorRegisterView
{
public:
    QLineEdit *name;
    QComboBox *sex;
    QLineEdit *password;
    QLineEdit *confirm_password;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *office;
    QComboBox *position;
    QToolButton *confirm;
    QToolButton *cancel;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *phoneNo;
    QDateEdit *dateEdit;
    QLabel *tip;
    QLabel *label_13;
    QLineEdit *username;
    QLineEdit *bornYear;
    QLabel *label_14;

    void setupUi(QDialog *DoctorRegisterView)
    {
        if (DoctorRegisterView->objectName().isEmpty())
            DoctorRegisterView->setObjectName(QStringLiteral("DoctorRegisterView"));
        DoctorRegisterView->resize(320, 240);
        name = new QLineEdit(DoctorRegisterView);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(80, 83, 101, 20));
        sex = new QComboBox(DoctorRegisterView);
        sex->addItem(QString());
        sex->addItem(QString());
        sex->addItem(QString());
        sex->setObjectName(QStringLiteral("sex"));
        sex->setGeometry(QRect(241, 83, 60, 20));
        password = new QLineEdit(DoctorRegisterView);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(80, 37, 220, 20));
        password->setEchoMode(QLineEdit::Password);
        confirm_password = new QLineEdit(DoctorRegisterView);
        confirm_password->setObjectName(QStringLiteral("confirm_password"));
        confirm_password->setGeometry(QRect(80, 60, 220, 20));
        confirm_password->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(DoctorRegisterView);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 60, 60, 20));
        label_4 = new QLabel(DoctorRegisterView);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 83, 60, 20));
        label_5 = new QLabel(DoctorRegisterView);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(192, 83, 40, 20));
        label_6 = new QLabel(DoctorRegisterView);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 106, 60, 20));
        label_7 = new QLabel(DoctorRegisterView);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 129, 60, 21));
        label_8 = new QLabel(DoctorRegisterView);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 152, 60, 20));
        office = new QComboBox(DoctorRegisterView);
        office->addItem(QString());
        office->addItem(QString());
        office->addItem(QString());
        office->addItem(QString());
        office->addItem(QString());
        office->addItem(QString());
        office->addItem(QString());
        office->addItem(QString());
        office->setObjectName(QStringLiteral("office"));
        office->setGeometry(QRect(80, 106, 100, 20));
        position = new QComboBox(DoctorRegisterView);
        position->addItem(QString());
        position->addItem(QString());
        position->addItem(QString());
        position->addItem(QString());
        position->addItem(QString());
        position->addItem(QString());
        position->addItem(QString());
        position->setObjectName(QStringLiteral("position"));
        position->setGeometry(QRect(201, 106, 100, 20));
        confirm = new QToolButton(DoctorRegisterView);
        confirm->setObjectName(QStringLiteral("confirm"));
        confirm->setGeometry(QRect(72, 200, 50, 25));
        cancel = new QToolButton(DoctorRegisterView);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(202, 200, 50, 25));
        label_9 = new QLabel(DoctorRegisterView);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(450, 170, 60, 20));
        label_10 = new QLabel(DoctorRegisterView);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(840, 320, 60, 20));
        label_11 = new QLabel(DoctorRegisterView);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(420, 190, 60, 20));
        label_12 = new QLabel(DoctorRegisterView);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 37, 60, 20));
        phoneNo = new QLineEdit(DoctorRegisterView);
        phoneNo->setObjectName(QStringLiteral("phoneNo"));
        phoneNo->setGeometry(QRect(80, 152, 220, 20));
        dateEdit = new QDateEdit(DoctorRegisterView);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(80, 129, 81, 20));
        tip = new QLabel(DoctorRegisterView);
        tip->setObjectName(QStringLiteral("tip"));
        tip->setGeometry(QRect(20, 178, 281, 20));
        tip->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(DoctorRegisterView);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 14, 60, 20));
        username = new QLineEdit(DoctorRegisterView);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(80, 14, 220, 20));
        username->setEchoMode(QLineEdit::Normal);
        bornYear = new QLineEdit(DoctorRegisterView);
        bornYear->setObjectName(QStringLiteral("bornYear"));
        bornYear->setGeometry(QRect(230, 129, 71, 20));
        label_14 = new QLabel(DoctorRegisterView);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(171, 129, 61, 20));
        QWidget::setTabOrder(username, password);
        QWidget::setTabOrder(password, confirm_password);
        QWidget::setTabOrder(confirm_password, name);
        QWidget::setTabOrder(name, sex);
        QWidget::setTabOrder(sex, office);
        QWidget::setTabOrder(office, position);
        QWidget::setTabOrder(position, dateEdit);
        QWidget::setTabOrder(dateEdit, phoneNo);
        QWidget::setTabOrder(phoneNo, bornYear);
        QWidget::setTabOrder(bornYear, confirm);
        QWidget::setTabOrder(confirm, cancel);

        retranslateUi(DoctorRegisterView);

        QMetaObject::connectSlotsByName(DoctorRegisterView);
    } // setupUi

    void retranslateUi(QDialog *DoctorRegisterView)
    {
        DoctorRegisterView->setWindowTitle(QApplication::translate("DoctorRegisterView", "Dialog", nullptr));
        sex->setItemText(0, QString());
        sex->setItemText(1, QApplication::translate("DoctorRegisterView", "\347\224\267", nullptr));
        sex->setItemText(2, QApplication::translate("DoctorRegisterView", "\345\245\263", nullptr));

        label_3->setText(QApplication::translate("DoctorRegisterView", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        label_4->setText(QApplication::translate("DoctorRegisterView", "\345\214\273\347\224\237\345\247\223\345\220\215\357\274\232", nullptr));
        label_5->setText(QApplication::translate("DoctorRegisterView", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_6->setText(QApplication::translate("DoctorRegisterView", "\347\247\221\345\256\244\350\201\214\344\275\215\357\274\232", nullptr));
        label_7->setText(QApplication::translate("DoctorRegisterView", "\345\205\245\350\201\214\346\227\266\351\227\264\357\274\232", nullptr));
        label_8->setText(QApplication::translate("DoctorRegisterView", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", nullptr));
        office->setItemText(0, QString());
        office->setItemText(1, QApplication::translate("DoctorRegisterView", "\345\206\205\347\247\221", nullptr));
        office->setItemText(2, QApplication::translate("DoctorRegisterView", "\345\244\226\347\247\221", nullptr));
        office->setItemText(3, QApplication::translate("DoctorRegisterView", "\345\246\207\344\272\247\347\247\221", nullptr));
        office->setItemText(4, QApplication::translate("DoctorRegisterView", "\345\204\277\347\247\221", nullptr));
        office->setItemText(5, QApplication::translate("DoctorRegisterView", "\347\232\256\350\202\244\346\200\247\347\227\205\347\247\221", nullptr));
        office->setItemText(6, QApplication::translate("DoctorRegisterView", "\347\262\276\347\245\236\345\277\203\347\220\206\347\247\221", nullptr));
        office->setItemText(7, QApplication::translate("DoctorRegisterView", "\345\205\266\344\273\226", nullptr));

        position->setItemText(0, QString());
        position->setItemText(1, QApplication::translate("DoctorRegisterView", "\344\270\273\344\273\273", nullptr));
        position->setItemText(2, QApplication::translate("DoctorRegisterView", "\345\211\257\344\270\273\344\273\273", nullptr));
        position->setItemText(3, QApplication::translate("DoctorRegisterView", "\344\270\273\346\262\273\345\214\273\345\270\210", nullptr));
        position->setItemText(4, QApplication::translate("DoctorRegisterView", "\345\214\273\345\270\210", nullptr));
        position->setItemText(5, QApplication::translate("DoctorRegisterView", "\345\212\251\347\220\206\345\214\273\345\270\210", nullptr));
        position->setItemText(6, QApplication::translate("DoctorRegisterView", "\345\256\236\344\271\240\347\224\237", nullptr));

        confirm->setText(QApplication::translate("DoctorRegisterView", "\347\241\256\345\256\232", nullptr));
        cancel->setText(QApplication::translate("DoctorRegisterView", "\345\217\226\346\266\210", nullptr));
        label_9->setText(QApplication::translate("DoctorRegisterView", "\345\214\273\347\224\237\347\274\226\345\217\267\357\274\232", nullptr));
        label_10->setText(QApplication::translate("DoctorRegisterView", "\345\214\273\347\224\237\347\274\226\345\217\267\357\274\232", nullptr));
        label_11->setText(QApplication::translate("DoctorRegisterView", "\345\214\273\347\224\237\347\274\226\345\217\267\357\274\232", nullptr));
        label_12->setText(QApplication::translate("DoctorRegisterView", "\350\256\276\347\275\256\345\257\206\347\240\201\357\274\232", nullptr));
        dateEdit->setDisplayFormat(QApplication::translate("DoctorRegisterView", "yyyy/MM/dd", nullptr));
        tip->setText(QString());
        label_13->setText(QApplication::translate("DoctorRegisterView", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_14->setText(QApplication::translate("DoctorRegisterView", "\345\207\272\347\224\237\345\271\264\344\273\275\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorRegisterView: public Ui_DoctorRegisterView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORREGISTERVIEW_H
