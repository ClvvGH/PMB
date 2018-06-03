/********************************************************************************
** Form generated from reading UI file 'securityinfoview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECURITYINFOVIEW_H
#define UI_SECURITYINFOVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecurityInfoView
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *backButton;

    void setupUi(QWidget *SecurityInfoView)
    {
        if (SecurityInfoView->objectName().isEmpty())
            SecurityInfoView->setObjectName(QStringLiteral("SecurityInfoView"));
        SecurityInfoView->resize(320, 240);
        label = new QLabel(SecurityInfoView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(67, 92, 54, 12));
        label_2 = new QLabel(SecurityInfoView);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(137, 92, 54, 12));
        pushButton = new QPushButton(SecurityInfoView);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 170, 75, 23));
        backButton = new QPushButton(SecurityInfoView);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 10, 61, 23));

        retranslateUi(SecurityInfoView);

        QMetaObject::connectSlotsByName(SecurityInfoView);
    } // setupUi

    void retranslateUi(QWidget *SecurityInfoView)
    {
        SecurityInfoView->setWindowTitle(QApplication::translate("SecurityInfoView", "Form", nullptr));
        label->setText(QApplication::translate("SecurityInfoView", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QApplication::translate("SecurityInfoView", "\347\224\250\346\210\267\345\220\215", nullptr));
        pushButton->setText(QApplication::translate("SecurityInfoView", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        backButton->setText(QApplication::translate("SecurityInfoView", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecurityInfoView: public Ui_SecurityInfoView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECURITYINFOVIEW_H
