/********************************************************************************
** Form generated from reading UI file 'chosepatientview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOSEPATIENTVIEW_H
#define UI_CHOSEPATIENTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChosePatientView
{
public:
    QLabel *label;
    QPushButton *backButton;
    QLineEdit *name;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QPushButton *queryButton;
    QLineEdit *id;

    void setupUi(QWidget *ChosePatientView)
    {
        if (ChosePatientView->objectName().isEmpty())
            ChosePatientView->setObjectName(QStringLiteral("ChosePatientView"));
        ChosePatientView->resize(320, 240);
        label = new QLabel(ChosePatientView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 11, 54, 20));
        backButton = new QPushButton(ChosePatientView);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 11, 41, 23));
        name = new QLineEdit(ChosePatientView);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(130, 41, 81, 20));
        label_2 = new QLabel(ChosePatientView);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 41, 54, 20));
        tableWidget = new QTableWidget(ChosePatientView);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 71, 280, 150));
        tableWidget->setStyleSheet(QStringLiteral(""));
        queryButton = new QPushButton(ChosePatientView);
        queryButton->setObjectName(QStringLiteral("queryButton"));
        queryButton->setGeometry(QRect(232, 41, 61, 23));
        id = new QLineEdit(ChosePatientView);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(130, 11, 81, 20));

        retranslateUi(ChosePatientView);

        QMetaObject::connectSlotsByName(ChosePatientView);
    } // setupUi

    void retranslateUi(QWidget *ChosePatientView)
    {
        ChosePatientView->setWindowTitle(QApplication::translate("ChosePatientView", "Form", nullptr));
        label->setText(QApplication::translate("ChosePatientView", "\347\274\226\345\217\267", nullptr));
        backButton->setText(QApplication::translate("ChosePatientView", "\350\277\224\345\233\236", nullptr));
        label_2->setText(QApplication::translate("ChosePatientView", "\345\247\223\345\220\215", nullptr));
        queryButton->setText(QApplication::translate("ChosePatientView", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChosePatientView: public Ui_ChosePatientView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOSEPATIENTVIEW_H
