/********************************************************************************
** Form generated from reading UI file 'treatview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREATVIEW_H
#define UI_TREATVIEW_H

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

class Ui_TreatView
{
public:
    QPushButton *backButton;
    QPushButton *leftButton;
    QPushButton *rightButton;
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
    QLabel *label;
    QLineEdit *disease;
    QPushButton *submitButton;
    QLineEdit *name;
    QLabel *label_6;

    void setupUi(QWidget *TreatView)
    {
        if (TreatView->objectName().isEmpty())
            TreatView->setObjectName(QStringLiteral("TreatView"));
        TreatView->resize(320, 240);
        backButton = new QPushButton(TreatView);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(6, 4, 51, 23));
        leftButton = new QPushButton(TreatView);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        leftButton->setGeometry(QRect(10, 100, 20, 80));
        rightButton = new QPushButton(TreatView);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        rightButton->setGeometry(QRect(290, 100, 20, 80));
        stackedWidget = new QStackedWidget(TreatView);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(35, 65, 250, 171));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(5, 5, 60, 20));
        description = new QPlainTextEdit(page);
        description->setObjectName(QStringLiteral("description"));
        description->setGeometry(QRect(5, 30, 240, 130));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        diagnose = new QPlainTextEdit(page_2);
        diagnose->setObjectName(QStringLiteral("diagnose"));
        diagnose->setGeometry(QRect(5, 30, 240, 130));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(5, 5, 81, 20));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        advice = new QPlainTextEdit(page_3);
        advice->setObjectName(QStringLiteral("advice"));
        advice->setGeometry(QRect(5, 30, 240, 130));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(5, 5, 60, 20));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        prescription = new QPlainTextEdit(page_4);
        prescription->setObjectName(QStringLiteral("prescription"));
        prescription->setGeometry(QRect(5, 30, 240, 130));
        label_5 = new QLabel(page_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(5, 5, 60, 20));
        stackedWidget->addWidget(page_4);
        label = new QLabel(TreatView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(134, 39, 41, 20));
        disease = new QLineEdit(TreatView);
        disease->setObjectName(QStringLiteral("disease"));
        disease->setGeometry(QRect(173, 39, 71, 20));
        submitButton = new QPushButton(TreatView);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setGeometry(QRect(251, 39, 61, 23));
        name = new QLineEdit(TreatView);
        name->setObjectName(QStringLiteral("name"));
        name->setEnabled(false);
        name->setGeometry(QRect(71, 39, 51, 20));
        label_6 = new QLabel(TreatView);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(8, 39, 61, 20));

        retranslateUi(TreatView);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(TreatView);
    } // setupUi

    void retranslateUi(QWidget *TreatView)
    {
        TreatView->setWindowTitle(QApplication::translate("TreatView", "Form", nullptr));
        backButton->setText(QApplication::translate("TreatView", "\350\277\224\345\233\236", nullptr));
        leftButton->setText(QApplication::translate("TreatView", "<", nullptr));
        rightButton->setText(QApplication::translate("TreatView", ">", nullptr));
        label_2->setText(QApplication::translate("TreatView", " \347\227\205\346\203\205\346\217\217\350\277\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("TreatView", " \350\257\212\346\226\255\357\274\232", nullptr));
        label_4->setText(QApplication::translate("TreatView", " \345\273\272\350\256\256\357\274\232", nullptr));
        label_5->setText(QApplication::translate("TreatView", " \345\244\204\346\226\271\357\274\232", nullptr));
        label->setText(QApplication::translate("TreatView", "\347\227\205\345\233\240\357\274\232", nullptr));
        submitButton->setText(QApplication::translate("TreatView", "\346\217\220\344\272\244", nullptr));
        name->setText(QString());
        label_6->setText(QApplication::translate("TreatView", "\346\202\243\350\200\205\345\247\223\345\220\215\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TreatView: public Ui_TreatView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREATVIEW_H
