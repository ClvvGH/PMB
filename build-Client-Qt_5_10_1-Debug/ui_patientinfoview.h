/********************************************************************************
** Form generated from reading UI file 'patientinfoview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTINFOVIEW_H
#define UI_PATIENTINFOVIEW_H

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

class Ui_PatientInfoView
{
public:
    QLabel *label;
    QLineEdit *name;
    QLabel *label_2;
    QLineEdit *sex;
    QLineEdit *age;
    QLabel *label_3;
    QLineEdit *tel;
    QLabel *label_4;
    QPushButton *treatMentButton;
    QPushButton *backButton;
    QPushButton *examinationButton;
    QPushButton *treat;
    QLabel *photo;

    void setupUi(QWidget *PatientInfoView)
    {
        if (PatientInfoView->objectName().isEmpty())
            PatientInfoView->setObjectName(QStringLiteral("PatientInfoView"));
        PatientInfoView->resize(320, 240);
        label = new QLabel(PatientInfoView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(151, 40, 54, 20));
        name = new QLineEdit(PatientInfoView);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(191, 40, 113, 20));
        label_2 = new QLabel(PatientInfoView);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 75, 54, 20));
        sex = new QLineEdit(PatientInfoView);
        sex->setObjectName(QStringLiteral("sex"));
        sex->setGeometry(QRect(190, 75, 113, 20));
        age = new QLineEdit(PatientInfoView);
        age->setObjectName(QStringLiteral("age"));
        age->setGeometry(QRect(190, 107, 113, 20));
        label_3 = new QLabel(PatientInfoView);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 107, 54, 20));
        tel = new QLineEdit(PatientInfoView);
        tel->setObjectName(QStringLiteral("tel"));
        tel->setGeometry(QRect(190, 140, 113, 20));
        label_4 = new QLabel(PatientInfoView);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(130, 140, 54, 20));
        treatMentButton = new QPushButton(PatientInfoView);
        treatMentButton->setObjectName(QStringLiteral("treatMentButton"));
        treatMentButton->setGeometry(QRect(28, 176, 75, 51));
        backButton = new QPushButton(PatientInfoView);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 10, 75, 23));
        examinationButton = new QPushButton(PatientInfoView);
        examinationButton->setObjectName(QStringLiteral("examinationButton"));
        examinationButton->setGeometry(QRect(126, 176, 75, 51));
        treat = new QPushButton(PatientInfoView);
        treat->setObjectName(QStringLiteral("treat"));
        treat->setGeometry(QRect(225, 176, 75, 51));
        photo = new QLabel(PatientInfoView);
        photo->setObjectName(QStringLiteral("photo"));
        photo->setGeometry(QRect(30, 59, 81, 91));
        photo->setAlignment(Qt::AlignCenter);

        retranslateUi(PatientInfoView);

        QMetaObject::connectSlotsByName(PatientInfoView);
    } // setupUi

    void retranslateUi(QWidget *PatientInfoView)
    {
        PatientInfoView->setWindowTitle(QApplication::translate("PatientInfoView", "Form", nullptr));
        label->setText(QApplication::translate("PatientInfoView", "\345\247\223\345\220\215", nullptr));
        label_2->setText(QApplication::translate("PatientInfoView", "\346\200\247\345\210\253", nullptr));
        label_3->setText(QApplication::translate("PatientInfoView", "\345\271\264\351\276\204", nullptr));
        label_4->setText(QApplication::translate("PatientInfoView", "\350\201\224\347\263\273\346\226\271\345\274\217", nullptr));
        treatMentButton->setText(QApplication::translate("PatientInfoView", "\345\214\273\347\226\227\350\256\260\345\275\225", nullptr));
        backButton->setText(QApplication::translate("PatientInfoView", "\350\277\224\345\233\236", nullptr));
        examinationButton->setText(QApplication::translate("PatientInfoView", "\344\275\223\346\243\200\350\256\260\345\275\225", nullptr));
        treat->setText(QApplication::translate("PatientInfoView", "\351\227\256\350\257\212", nullptr));
        photo->setText(QApplication::translate("PatientInfoView", "\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientInfoView: public Ui_PatientInfoView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTINFOVIEW_H
