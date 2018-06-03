/********************************************************************************
** Form generated from reading UI file 'selfinfoview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELFINFOVIEW_H
#define UI_SELFINFOVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelfInfoView
{
public:
    QPushButton *logoutButton;
    QLabel *label;
    QPushButton *editInfoButton;
    QPushButton *securityButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *tel;
    QLabel *departmentLabel;
    QLabel *label_6;
    QLineEdit *name;
    QLabel *label_2;
    QLabel *label_8;
    QLineEdit *age;
    QLabel *label_7;
    QLabel *positionLabel;
    QLabel *label_3;
    QLineEdit *bornYear;
    QComboBox *sex;
    QComboBox *department;
    QComboBox *position;
    QWidget *page_2;
    QLineEdit *tel_2;
    QLabel *label_9;
    QLineEdit *name_2;
    QLabel *label_4;
    QLabel *label_10;
    QLineEdit *age_2;
    QLabel *label_11;
    QLabel *label_5;
    QLineEdit *bornYear_2;
    QComboBox *sex_2;
    QPushButton *backButton;

    void setupUi(QWidget *SelfInfoView)
    {
        if (SelfInfoView->objectName().isEmpty())
            SelfInfoView->setObjectName(QStringLiteral("SelfInfoView"));
        SelfInfoView->resize(320, 240);
        logoutButton = new QPushButton(SelfInfoView);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));
        logoutButton->setGeometry(QRect(8, 187, 75, 23));
        label = new QLabel(SelfInfoView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(18, 47, 61, 61));
        label->setAlignment(Qt::AlignCenter);
        editInfoButton = new QPushButton(SelfInfoView);
        editInfoButton->setObjectName(QStringLiteral("editInfoButton"));
        editInfoButton->setGeometry(QRect(8, 127, 75, 23));
        securityButton = new QPushButton(SelfInfoView);
        securityButton->setObjectName(QStringLiteral("securityButton"));
        securityButton->setGeometry(QRect(8, 157, 75, 23));
        stackedWidget = new QStackedWidget(SelfInfoView);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(90, 20, 221, 211));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        tel = new QLineEdit(page);
        tel->setObjectName(QStringLiteral("tel"));
        tel->setEnabled(true);
        tel->setGeometry(QRect(66, 119, 140, 20));
        departmentLabel = new QLabel(page);
        departmentLabel->setObjectName(QStringLiteral("departmentLabel"));
        departmentLabel->setGeometry(QRect(6, 154, 54, 20));
        label_6 = new QLabel(page);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(9, 83, 54, 20));
        name = new QLineEdit(page);
        name->setObjectName(QStringLiteral("name"));
        name->setEnabled(true);
        name->setGeometry(QRect(66, 18, 140, 20));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(11, 18, 54, 20));
        label_8 = new QLabel(page);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(125, 86, 41, 20));
        age = new QLineEdit(page);
        age->setObjectName(QStringLiteral("age"));
        age->setEnabled(true);
        age->setGeometry(QRect(155, 83, 51, 20));
        label_7 = new QLabel(page);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(9, 119, 54, 20));
        positionLabel = new QLabel(page);
        positionLabel->setObjectName(QStringLiteral("positionLabel"));
        positionLabel->setGeometry(QRect(12, 189, 54, 20));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(9, 53, 54, 20));
        bornYear = new QLineEdit(page);
        bornYear->setObjectName(QStringLiteral("bornYear"));
        bornYear->setEnabled(true);
        bornYear->setGeometry(QRect(66, 83, 51, 20));
        sex = new QComboBox(page);
        sex->addItem(QString());
        sex->addItem(QString());
        sex->setObjectName(QStringLiteral("sex"));
        sex->setGeometry(QRect(66, 53, 140, 20));
        department = new QComboBox(page);
        department->addItem(QString());
        department->addItem(QString());
        department->addItem(QString());
        department->addItem(QString());
        department->addItem(QString());
        department->addItem(QString());
        department->setObjectName(QStringLiteral("department"));
        department->setGeometry(QRect(70, 157, 140, 20));
        position = new QComboBox(page);
        position->addItem(QString());
        position->addItem(QString());
        position->addItem(QString());
        position->addItem(QString());
        position->addItem(QString());
        position->addItem(QString());
        position->setObjectName(QStringLiteral("position"));
        position->setGeometry(QRect(69, 187, 140, 20));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        tel_2 = new QLineEdit(page_2);
        tel_2->setObjectName(QStringLiteral("tel_2"));
        tel_2->setEnabled(true);
        tel_2->setGeometry(QRect(70, 153, 140, 20));
        label_9 = new QLabel(page_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(13, 117, 54, 20));
        name_2 = new QLineEdit(page_2);
        name_2->setObjectName(QStringLiteral("name_2"));
        name_2->setEnabled(true);
        name_2->setGeometry(QRect(70, 44, 140, 20));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(15, 44, 54, 20));
        label_10 = new QLabel(page_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(129, 117, 41, 20));
        age_2 = new QLineEdit(page_2);
        age_2->setObjectName(QStringLiteral("age_2"));
        age_2->setEnabled(true);
        age_2->setGeometry(QRect(159, 117, 51, 20));
        label_11 = new QLabel(page_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(13, 153, 54, 20));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(13, 79, 54, 20));
        bornYear_2 = new QLineEdit(page_2);
        bornYear_2->setObjectName(QStringLiteral("bornYear_2"));
        bornYear_2->setEnabled(true);
        bornYear_2->setGeometry(QRect(70, 117, 51, 20));
        sex_2 = new QComboBox(page_2);
        sex_2->addItem(QString());
        sex_2->addItem(QString());
        sex_2->setObjectName(QStringLiteral("sex_2"));
        sex_2->setGeometry(QRect(70, 80, 140, 20));
        stackedWidget->addWidget(page_2);
        backButton = new QPushButton(SelfInfoView);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 0, 41, 23));
        QWidget::setTabOrder(editInfoButton, securityButton);
        QWidget::setTabOrder(securityButton, logoutButton);

        retranslateUi(SelfInfoView);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SelfInfoView);
    } // setupUi

    void retranslateUi(QWidget *SelfInfoView)
    {
        SelfInfoView->setWindowTitle(QApplication::translate("SelfInfoView", "Form", nullptr));
        logoutButton->setText(QApplication::translate("SelfInfoView", "\346\263\250\351\224\200", nullptr));
        label->setText(QApplication::translate("SelfInfoView", "\347\205\247\347\211\207", nullptr));
        editInfoButton->setText(QApplication::translate("SelfInfoView", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        securityButton->setText(QApplication::translate("SelfInfoView", "\345\256\211\345\205\250\344\277\241\346\201\257", nullptr));
        tel->setText(QString());
        departmentLabel->setText(QApplication::translate("SelfInfoView", "\346\211\200\345\234\250\351\203\250\351\227\250", nullptr));
        label_6->setText(QApplication::translate("SelfInfoView", "\345\207\272\347\224\237\345\271\264\344\273\275", nullptr));
        label_2->setText(QApplication::translate("SelfInfoView", "\345\247\223\345\220\215", nullptr));
        label_8->setText(QApplication::translate("SelfInfoView", "\345\271\264\351\276\204", nullptr));
        label_7->setText(QApplication::translate("SelfInfoView", "\350\201\224\347\263\273\346\226\271\345\274\217", nullptr));
        positionLabel->setText(QApplication::translate("SelfInfoView", "\350\201\214\344\275\215", nullptr));
        label_3->setText(QApplication::translate("SelfInfoView", "\346\200\247\345\210\253", nullptr));
        sex->setItemText(0, QApplication::translate("SelfInfoView", "\347\224\267", nullptr));
        sex->setItemText(1, QApplication::translate("SelfInfoView", "\345\245\263", nullptr));

        department->setItemText(0, QApplication::translate("SelfInfoView", "\345\246\207\344\272\247\347\247\221", nullptr));
        department->setItemText(1, QApplication::translate("SelfInfoView", "\345\204\277\347\247\221", nullptr));
        department->setItemText(2, QApplication::translate("SelfInfoView", "\345\206\205\347\247\221", nullptr));
        department->setItemText(3, QApplication::translate("SelfInfoView", "\345\244\226\347\247\221", nullptr));
        department->setItemText(4, QApplication::translate("SelfInfoView", "\347\245\236\347\273\217\347\247\221", nullptr));
        department->setItemText(5, QApplication::translate("SelfInfoView", "\347\232\256\350\202\244\346\200\247\347\227\205\347\247\221", nullptr));

        position->setItemText(0, QApplication::translate("SelfInfoView", "\344\270\273\344\273\273", nullptr));
        position->setItemText(1, QApplication::translate("SelfInfoView", "\345\211\257\344\270\273\344\273\273", nullptr));
        position->setItemText(2, QApplication::translate("SelfInfoView", "\344\270\273\346\262\273\345\214\273\345\270\210", nullptr));
        position->setItemText(3, QApplication::translate("SelfInfoView", "\345\214\273\345\270\210", nullptr));
        position->setItemText(4, QApplication::translate("SelfInfoView", "\345\212\251\347\220\206\345\214\273\345\270\210", nullptr));
        position->setItemText(5, QApplication::translate("SelfInfoView", "\345\256\236\344\271\240\347\224\237", nullptr));

        tel_2->setText(QString());
        label_9->setText(QApplication::translate("SelfInfoView", "\345\207\272\347\224\237\345\271\264\344\273\275", nullptr));
        label_4->setText(QApplication::translate("SelfInfoView", "\345\247\223\345\220\215", nullptr));
        label_10->setText(QApplication::translate("SelfInfoView", "\345\271\264\351\276\204", nullptr));
        label_11->setText(QApplication::translate("SelfInfoView", "\350\201\224\347\263\273\346\226\271\345\274\217", nullptr));
        label_5->setText(QApplication::translate("SelfInfoView", "\346\200\247\345\210\253", nullptr));
        sex_2->setItemText(0, QApplication::translate("SelfInfoView", "\347\224\267", nullptr));
        sex_2->setItemText(1, QApplication::translate("SelfInfoView", "\345\245\263", nullptr));

        backButton->setText(QApplication::translate("SelfInfoView", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelfInfoView: public Ui_SelfInfoView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELFINFOVIEW_H
