/********************************************************************************
** Form generated from reading UI file 'treatlistview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREATLISTVIEW_H
#define UI_TREATLISTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TreatListView
{
public:
    QPushButton *backButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *TreatListView)
    {
        if (TreatListView->objectName().isEmpty())
            TreatListView->setObjectName(QStringLiteral("TreatListView"));
        TreatListView->resize(320, 240);
        backButton = new QPushButton(TreatListView);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 10, 41, 23));
        tableWidget = new QTableWidget(TreatListView);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 39, 280, 181));
        tableWidget->setStyleSheet(QStringLiteral(""));

        retranslateUi(TreatListView);

        QMetaObject::connectSlotsByName(TreatListView);
    } // setupUi

    void retranslateUi(QWidget *TreatListView)
    {
        TreatListView->setWindowTitle(QApplication::translate("TreatListView", "Form", nullptr));
        backButton->setText(QApplication::translate("TreatListView", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TreatListView: public Ui_TreatListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREATLISTVIEW_H
