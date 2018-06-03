/********************************************************************************
** Form generated from reading UI file 'patientlistview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTLISTVIEW_H
#define UI_PATIENTLISTVIEW_H

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

class Ui_PatientListView
{
public:
    QLineEdit *id;
    QLineEdit *name;
    QLabel *label;
    QLabel *label_2;
    QPushButton *queryButton;
    QTableWidget *tableWidget;
    QPushButton *backButton;

    void setupUi(QWidget *PatientListView)
    {
        if (PatientListView->objectName().isEmpty())
            PatientListView->setObjectName(QStringLiteral("PatientListView"));
        PatientListView->resize(320, 240);
        id = new QLineEdit(PatientListView);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(130, 10, 81, 20));
        name = new QLineEdit(PatientListView);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(130, 40, 81, 20));
        label = new QLabel(PatientListView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 10, 54, 20));
        label_2 = new QLabel(PatientListView);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 40, 54, 20));
        queryButton = new QPushButton(PatientListView);
        queryButton->setObjectName(QStringLiteral("queryButton"));
        queryButton->setGeometry(QRect(232, 40, 61, 23));
        tableWidget = new QTableWidget(PatientListView);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 70, 280, 150));
        tableWidget->setStyleSheet(QStringLiteral(""));
        backButton = new QPushButton(PatientListView);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 10, 41, 23));

        retranslateUi(PatientListView);

        QMetaObject::connectSlotsByName(PatientListView);
    } // setupUi

    void retranslateUi(QWidget *PatientListView)
    {
        PatientListView->setWindowTitle(QApplication::translate("PatientListView", "Form", nullptr));
        label->setText(QApplication::translate("PatientListView", "\347\274\226\345\217\267", nullptr));
        label_2->setText(QApplication::translate("PatientListView", "\345\247\223\345\220\215", nullptr));
        queryButton->setText(QApplication::translate("PatientListView", "\346\237\245\350\257\242", nullptr));
        backButton->setText(QApplication::translate("PatientListView", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientListView: public Ui_PatientListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTLISTVIEW_H
