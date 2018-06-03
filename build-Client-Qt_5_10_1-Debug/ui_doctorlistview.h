/********************************************************************************
** Form generated from reading UI file 'doctorlistview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORLISTVIEW_H
#define UI_DOCTORLISTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoctorListView
{
public:
    QPushButton *pushButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *DoctorListView)
    {
        if (DoctorListView->objectName().isEmpty())
            DoctorListView->setObjectName(QStringLiteral("DoctorListView"));
        DoctorListView->resize(320, 240);
        pushButton = new QPushButton(DoctorListView);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(5, 4, 75, 23));
        tableWidget = new QTableWidget(DoctorListView);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 30, 280, 200));

        retranslateUi(DoctorListView);

        QMetaObject::connectSlotsByName(DoctorListView);
    } // setupUi

    void retranslateUi(QWidget *DoctorListView)
    {
        DoctorListView->setWindowTitle(QApplication::translate("DoctorListView", "Form", nullptr));
        pushButton->setText(QApplication::translate("DoctorListView", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorListView: public Ui_DoctorListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORLISTVIEW_H
