/********************************************************************************
** Form generated from reading UI file 'changepasswordview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORDVIEW_H
#define UI_CHANGEPASSWORDVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangePasswordView
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *elderPassword;
    QLineEdit *newPassword;
    QLabel *label_2;
    QLineEdit *confirmPassword;
    QLabel *label_3;
    QLabel *tip;
    QPushButton *pushButton_2;

    void setupUi(QWidget *ChangePasswordView)
    {
        if (ChangePasswordView->objectName().isEmpty())
            ChangePasswordView->setObjectName(QStringLiteral("ChangePasswordView"));
        ChangePasswordView->resize(320, 240);
        pushButton = new QPushButton(ChangePasswordView);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 180, 75, 23));
        label = new QLabel(ChangePasswordView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(41, 50, 71, 20));
        elderPassword = new QLineEdit(ChangePasswordView);
        elderPassword->setObjectName(QStringLiteral("elderPassword"));
        elderPassword->setGeometry(QRect(115, 49, 150, 20));
        elderPassword->setEchoMode(QLineEdit::Password);
        newPassword = new QLineEdit(ChangePasswordView);
        newPassword->setObjectName(QStringLiteral("newPassword"));
        newPassword->setGeometry(QRect(115, 84, 150, 20));
        newPassword->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(ChangePasswordView);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(41, 85, 71, 20));
        confirmPassword = new QLineEdit(ChangePasswordView);
        confirmPassword->setObjectName(QStringLiteral("confirmPassword"));
        confirmPassword->setGeometry(QRect(115, 119, 150, 20));
        confirmPassword->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(ChangePasswordView);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(41, 120, 71, 20));
        tip = new QLabel(ChangePasswordView);
        tip->setObjectName(QStringLiteral("tip"));
        tip->setGeometry(QRect(43, 155, 221, 20));
        tip->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(ChangePasswordView);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 10, 75, 23));

        retranslateUi(ChangePasswordView);

        QMetaObject::connectSlotsByName(ChangePasswordView);
    } // setupUi

    void retranslateUi(QWidget *ChangePasswordView)
    {
        ChangePasswordView->setWindowTitle(QApplication::translate("ChangePasswordView", "Form", nullptr));
        pushButton->setText(QApplication::translate("ChangePasswordView", "\346\217\220\344\272\244\344\277\256\346\224\271", nullptr));
        label->setText(QApplication::translate("ChangePasswordView", "\350\276\223\345\205\245\346\227\247\345\257\206\347\240\201\357\274\232", nullptr));
        label_2->setText(QApplication::translate("ChangePasswordView", "\350\256\276\347\275\256\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QApplication::translate("ChangePasswordView", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        tip->setText(QString());
        pushButton_2->setText(QApplication::translate("ChangePasswordView", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePasswordView: public Ui_ChangePasswordView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORDVIEW_H
