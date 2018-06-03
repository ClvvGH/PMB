/********************************************************************************
** Form generated from reading UI file 'patientmainview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTMAINVIEW_H
#define UI_PATIENTMAINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientMainView
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *treatment;
    QPushButton *selfInfo;
    QPushButton *doctorlist;
    QPushButton *examination;

    void setupUi(QWidget *PatientMainView)
    {
        if (PatientMainView->objectName().isEmpty())
            PatientMainView->setObjectName(QStringLiteral("PatientMainView"));
        PatientMainView->resize(320, 240);
        layoutWidget = new QWidget(PatientMainView);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 271, 151));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        treatment = new QPushButton(layoutWidget);
        treatment->setObjectName(QStringLiteral("treatment"));

        gridLayout->addWidget(treatment, 3, 2, 1, 1);

        selfInfo = new QPushButton(layoutWidget);
        selfInfo->setObjectName(QStringLiteral("selfInfo"));

        gridLayout->addWidget(selfInfo, 2, 0, 1, 1);

        doctorlist = new QPushButton(layoutWidget);
        doctorlist->setObjectName(QStringLiteral("doctorlist"));

        gridLayout->addWidget(doctorlist, 2, 2, 1, 1);

        examination = new QPushButton(layoutWidget);
        examination->setObjectName(QStringLiteral("examination"));

        gridLayout->addWidget(examination, 3, 0, 1, 1);


        retranslateUi(PatientMainView);

        QMetaObject::connectSlotsByName(PatientMainView);
    } // setupUi

    void retranslateUi(QWidget *PatientMainView)
    {
        PatientMainView->setWindowTitle(QApplication::translate("PatientMainView", "Form", nullptr));
        treatment->setText(QApplication::translate("PatientMainView", "\345\214\273\347\226\227\344\277\241\346\201\257", nullptr));
        selfInfo->setText(QApplication::translate("PatientMainView", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        doctorlist->setText(QApplication::translate("PatientMainView", "\345\214\273\347\224\237\351\200\232\350\256\257\345\275\225", nullptr));
        examination->setText(QApplication::translate("PatientMainView", "\346\243\200\346\237\245\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientMainView: public Ui_PatientMainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTMAINVIEW_H
