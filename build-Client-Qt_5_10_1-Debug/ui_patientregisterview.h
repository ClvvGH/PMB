/********************************************************************************
** Form generated from reading UI file 'patientregisterview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTREGISTERVIEW_H
#define UI_PATIENTREGISTERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_PatientRegisterView
{
public:
    QComboBox *sex;
    QLabel *label_4;
    QLabel *label_13;
    QLineEdit *confirm_password;
    QToolButton *confirm;
    QLineEdit *phoneNo;
    QLineEdit *name;
    QLabel *label_12;
    QLineEdit *password;
    QLabel *tip;
    QLabel *label_8;
    QLabel *label_5;
    QLineEdit *username;
    QLabel *label_14;
    QLabel *label_3;
    QLineEdit *bornYear;
    QToolButton *cancel;

    void setupUi(QDialog *PatientRegisterView)
    {
        if (PatientRegisterView->objectName().isEmpty())
            PatientRegisterView->setObjectName(QStringLiteral("PatientRegisterView"));
        PatientRegisterView->resize(320, 240);
        sex = new QComboBox(PatientRegisterView);
        sex->addItem(QString());
        sex->addItem(QString());
        sex->addItem(QString());
        sex->setObjectName(QStringLiteral("sex"));
        sex->setGeometry(QRect(238, 93, 60, 20));
        label_4 = new QLabel(PatientRegisterView);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(17, 93, 60, 20));
        label_13 = new QLabel(PatientRegisterView);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(17, 24, 60, 20));
        confirm_password = new QLineEdit(PatientRegisterView);
        confirm_password->setObjectName(QStringLiteral("confirm_password"));
        confirm_password->setGeometry(QRect(77, 70, 220, 20));
        confirm_password->setEchoMode(QLineEdit::Password);
        confirm = new QToolButton(PatientRegisterView);
        confirm->setObjectName(QStringLiteral("confirm"));
        confirm->setGeometry(QRect(66, 196, 50, 25));
        phoneNo = new QLineEdit(PatientRegisterView);
        phoneNo->setObjectName(QStringLiteral("phoneNo"));
        phoneNo->setGeometry(QRect(77, 139, 220, 20));
        name = new QLineEdit(PatientRegisterView);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(77, 93, 101, 20));
        label_12 = new QLabel(PatientRegisterView);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(17, 47, 60, 20));
        password = new QLineEdit(PatientRegisterView);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(77, 47, 220, 20));
        password->setEchoMode(QLineEdit::Password);
        tip = new QLabel(PatientRegisterView);
        tip->setObjectName(QStringLiteral("tip"));
        tip->setGeometry(QRect(17, 169, 281, 20));
        tip->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(PatientRegisterView);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(17, 139, 60, 20));
        label_5 = new QLabel(PatientRegisterView);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(189, 93, 40, 20));
        username = new QLineEdit(PatientRegisterView);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(77, 24, 220, 20));
        username->setEchoMode(QLineEdit::Normal);
        label_14 = new QLabel(PatientRegisterView);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(17, 116, 61, 20));
        label_3 = new QLabel(PatientRegisterView);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(17, 70, 60, 20));
        bornYear = new QLineEdit(PatientRegisterView);
        bornYear->setObjectName(QStringLiteral("bornYear"));
        bornYear->setGeometry(QRect(77, 116, 71, 20));
        cancel = new QToolButton(PatientRegisterView);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(196, 196, 50, 25));
        QWidget::setTabOrder(username, password);
        QWidget::setTabOrder(password, confirm_password);
        QWidget::setTabOrder(confirm_password, name);
        QWidget::setTabOrder(name, sex);
        QWidget::setTabOrder(sex, bornYear);
        QWidget::setTabOrder(bornYear, phoneNo);
        QWidget::setTabOrder(phoneNo, confirm);
        QWidget::setTabOrder(confirm, cancel);

        retranslateUi(PatientRegisterView);

        QMetaObject::connectSlotsByName(PatientRegisterView);
    } // setupUi

    void retranslateUi(QDialog *PatientRegisterView)
    {
        PatientRegisterView->setWindowTitle(QApplication::translate("PatientRegisterView", "Dialog", nullptr));
        sex->setItemText(0, QString());
        sex->setItemText(1, QApplication::translate("PatientRegisterView", "\347\224\267", nullptr));
        sex->setItemText(2, QApplication::translate("PatientRegisterView", "\345\245\263", nullptr));

        label_4->setText(QApplication::translate("PatientRegisterView", "\346\202\243\350\200\205\345\247\223\345\220\215\357\274\232", nullptr));
        label_13->setText(QApplication::translate("PatientRegisterView", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        confirm->setText(QApplication::translate("PatientRegisterView", "\347\241\256\345\256\232", nullptr));
        label_12->setText(QApplication::translate("PatientRegisterView", "\350\256\276\347\275\256\345\257\206\347\240\201\357\274\232", nullptr));
        tip->setText(QString());
        label_8->setText(QApplication::translate("PatientRegisterView", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", nullptr));
        label_5->setText(QApplication::translate("PatientRegisterView", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_14->setText(QApplication::translate("PatientRegisterView", "\345\207\272\347\224\237\345\271\264\344\273\275\357\274\232", nullptr));
        label_3->setText(QApplication::translate("PatientRegisterView", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        cancel->setText(QApplication::translate("PatientRegisterView", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientRegisterView: public Ui_PatientRegisterView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTREGISTERVIEW_H
