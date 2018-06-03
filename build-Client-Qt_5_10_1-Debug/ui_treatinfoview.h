/********************************************************************************
** Form generated from reading UI file 'treatinfoview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREATINFOVIEW_H
#define UI_TREATINFOVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TreatInfoView
{
public:
    QLineEdit *DId;
    QLabel *label;
    QPushButton *leftButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_2;
    QPlainTextEdit *description;
    QWidget *page_2;
    QPlainTextEdit *diagnose;
    QLabel *label_3;
    QWidget *page_3;
    QPlainTextEdit *advice;
    QLabel *label_4;
    QWidget *page_4;
    QPlainTextEdit *prescription;
    QLabel *label_5;
    QPushButton *backButton;
    QPushButton *rightButton;
    QLineEdit *disease;
    QLabel *label_6;
    QLineEdit *doctorName;
    QLabel *label_7;
    QLineEdit *date;
    QLabel *label_8;

    void setupUi(QWidget *TreatInfoView)
    {
        if (TreatInfoView->objectName().isEmpty())
            TreatInfoView->setObjectName(QStringLiteral("TreatInfoView"));
        TreatInfoView->resize(320, 240);
        DId = new QLineEdit(TreatInfoView);
        DId->setObjectName(QStringLiteral("DId"));
        DId->setEnabled(false);
        DId->setGeometry(QRect(73, 39, 81, 20));
        label = new QLabel(TreatInfoView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(172, 39, 41, 20));
        leftButton = new QPushButton(TreatInfoView);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        leftButton->setGeometry(QRect(9, 112, 20, 80));
        stackedWidget = new QStackedWidget(TreatInfoView);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(35, 82, 250, 151));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(5, 5, 60, 20));
        description = new QPlainTextEdit(page);
        description->setObjectName(QStringLiteral("description"));
        description->setEnabled(false);
        description->setGeometry(QRect(5, 30, 240, 121));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        diagnose = new QPlainTextEdit(page_2);
        diagnose->setObjectName(QStringLiteral("diagnose"));
        diagnose->setEnabled(false);
        diagnose->setGeometry(QRect(5, 30, 240, 121));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(5, 5, 81, 20));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        advice = new QPlainTextEdit(page_3);
        advice->setObjectName(QStringLiteral("advice"));
        advice->setEnabled(false);
        advice->setGeometry(QRect(5, 30, 240, 121));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(5, 5, 60, 20));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        prescription = new QPlainTextEdit(page_4);
        prescription->setObjectName(QStringLiteral("prescription"));
        prescription->setEnabled(false);
        prescription->setGeometry(QRect(5, 30, 240, 121));
        label_5 = new QLabel(page_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(5, 5, 60, 20));
        stackedWidget->addWidget(page_4);
        backButton = new QPushButton(TreatInfoView);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(5, 4, 51, 23));
        rightButton = new QPushButton(TreatInfoView);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        rightButton->setGeometry(QRect(289, 113, 20, 80));
        disease = new QLineEdit(TreatInfoView);
        disease->setObjectName(QStringLiteral("disease"));
        disease->setEnabled(false);
        disease->setGeometry(QRect(211, 39, 91, 20));
        label_6 = new QLabel(TreatInfoView);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 39, 61, 20));
        doctorName = new QLineEdit(TreatInfoView);
        doctorName->setObjectName(QStringLiteral("doctorName"));
        doctorName->setEnabled(false);
        doctorName->setGeometry(QRect(73, 60, 81, 20));
        label_7 = new QLabel(TreatInfoView);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 60, 61, 20));
        date = new QLineEdit(TreatInfoView);
        date->setObjectName(QStringLiteral("date"));
        date->setEnabled(false);
        date->setGeometry(QRect(211, 60, 91, 20));
        label_8 = new QLabel(TreatInfoView);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(172, 60, 41, 20));

        retranslateUi(TreatInfoView);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TreatInfoView);
    } // setupUi

    void retranslateUi(QWidget *TreatInfoView)
    {
        TreatInfoView->setWindowTitle(QApplication::translate("TreatInfoView", "Form", nullptr));
        DId->setText(QString());
        label->setText(QApplication::translate("TreatInfoView", "\347\227\205\345\233\240\357\274\232", nullptr));
        leftButton->setText(QApplication::translate("TreatInfoView", "<", nullptr));
        label_2->setText(QApplication::translate("TreatInfoView", " \347\227\205\346\203\205\346\217\217\350\277\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("TreatInfoView", " \350\257\212\346\226\255\357\274\232", nullptr));
        label_4->setText(QApplication::translate("TreatInfoView", " \345\273\272\350\256\256\357\274\232", nullptr));
        label_5->setText(QApplication::translate("TreatInfoView", " \345\244\204\346\226\271\357\274\232", nullptr));
        backButton->setText(QApplication::translate("TreatInfoView", "\350\277\224\345\233\236", nullptr));
        rightButton->setText(QApplication::translate("TreatInfoView", ">", nullptr));
        label_6->setText(QApplication::translate("TreatInfoView", "\345\214\273\347\224\237\347\274\226\345\217\267\357\274\232", nullptr));
        doctorName->setText(QString());
        label_7->setText(QApplication::translate("TreatInfoView", "\345\214\273\347\224\237\345\247\223\345\220\215\357\274\232", nullptr));
        label_8->setText(QApplication::translate("TreatInfoView", "\346\227\266\351\227\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TreatInfoView: public Ui_TreatInfoView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREATINFOVIEW_H
