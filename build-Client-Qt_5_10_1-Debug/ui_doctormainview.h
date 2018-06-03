/********************************************************************************
** Form generated from reading UI file 'doctormainview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORMAINVIEW_H
#define UI_DOCTORMAINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoctorMainView
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;

    void setupUi(QWidget *DoctorMainView)
    {
        if (DoctorMainView->objectName().isEmpty())
            DoctorMainView->setObjectName(QStringLiteral("DoctorMainView"));
        DoctorMainView->resize(320, 240);
        layoutWidget = new QWidget(DoctorMainView);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 40, 271, 151));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 4, 0, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 2, 2, 1, 1);


        retranslateUi(DoctorMainView);

        QMetaObject::connectSlotsByName(DoctorMainView);
    } // setupUi

    void retranslateUi(QWidget *DoctorMainView)
    {
        DoctorMainView->setWindowTitle(QApplication::translate("DoctorMainView", "Form", nullptr));
        pushButton->setText(QApplication::translate("DoctorMainView", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        pushButton_2->setText(QApplication::translate("DoctorMainView", "\346\202\243\350\200\205\344\277\241\346\201\257", nullptr));
        pushButton_3->setText(QApplication::translate("DoctorMainView", "\351\227\256\350\257\212", nullptr));
        pushButton_5->setText(QApplication::translate("DoctorMainView", "\351\200\232\350\256\257\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorMainView: public Ui_DoctorMainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORMAINVIEW_H
