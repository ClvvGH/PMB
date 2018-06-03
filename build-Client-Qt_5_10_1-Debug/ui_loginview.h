/********************************************************************************
** Form generated from reading UI file 'loginview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINVIEW_H
#define UI_LOGINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_LoginView
{
public:
    QPushButton *LoginButton;
    QPushButton *Quitbutton;
    QRadioButton *DoctorButton;
    QRadioButton *PatientButton;
    QLabel *label;
    QLineEdit *username;
    QLineEdit *password;
    QLabel *label_2;
    QPushButton *RegisterButton;

    void setupUi(QDialog *LoginView)
    {
        if (LoginView->objectName().isEmpty())
            LoginView->setObjectName(QStringLiteral("LoginView"));
        LoginView->resize(320, 240);
        LoginButton = new QPushButton(LoginView);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));
        LoginButton->setGeometry(QRect(40, 190, 75, 23));
        Quitbutton = new QPushButton(LoginView);
        Quitbutton->setObjectName(QStringLiteral("Quitbutton"));
        Quitbutton->setGeometry(QRect(214, 190, 75, 23));
        DoctorButton = new QRadioButton(LoginView);
        DoctorButton->setObjectName(QStringLiteral("DoctorButton"));
        DoctorButton->setGeometry(QRect(80, 39, 51, 31));
        PatientButton = new QRadioButton(LoginView);
        PatientButton->setObjectName(QStringLiteral("PatientButton"));
        PatientButton->setGeometry(QRect(180, 39, 51, 31));
        label = new QLabel(LoginView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(57, 99, 50, 20));
        username = new QLineEdit(LoginView);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(107, 99, 150, 20));
        password = new QLineEdit(LoginView);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(107, 140, 150, 20));
        password->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(LoginView);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(57, 140, 50, 20));
        RegisterButton = new QPushButton(LoginView);
        RegisterButton->setObjectName(QStringLiteral("RegisterButton"));
        RegisterButton->setGeometry(QRect(127, 190, 75, 23));
        QWidget::setTabOrder(DoctorButton, PatientButton);
        QWidget::setTabOrder(PatientButton, username);
        QWidget::setTabOrder(username, password);
        QWidget::setTabOrder(password, LoginButton);
        QWidget::setTabOrder(LoginButton, RegisterButton);
        QWidget::setTabOrder(RegisterButton, Quitbutton);

        retranslateUi(LoginView);

        QMetaObject::connectSlotsByName(LoginView);
    } // setupUi

    void retranslateUi(QDialog *LoginView)
    {
        LoginView->setWindowTitle(QApplication::translate("LoginView", "Dialog", nullptr));
        LoginButton->setText(QApplication::translate("LoginView", "\347\231\273\351\231\206", nullptr));
        Quitbutton->setText(QApplication::translate("LoginView", "\351\200\200\345\207\272", nullptr));
        DoctorButton->setText(QApplication::translate("LoginView", "\345\214\273\347\224\237", nullptr));
        PatientButton->setText(QApplication::translate("LoginView", "\346\202\243\350\200\205", nullptr));
        label->setText(QApplication::translate("LoginView", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QApplication::translate("LoginView", "\345\257\206\347\240\201\357\274\232", nullptr));
        RegisterButton->setText(QApplication::translate("LoginView", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginView: public Ui_LoginView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINVIEW_H
