/********************************************************************************
** Form generated from reading UI file 'CashRegister.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASHREGISTER_H
#define UI_CASHREGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CashRegisterClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_scaner;
    QLabel *label_status;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pb_Intery;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pb_calculate;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pb_log;
    QSpacerItem *verticalSpacer_4;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *CashRegisterClass)
    {
        if (CashRegisterClass->objectName().isEmpty())
            CashRegisterClass->setObjectName(QString::fromUtf8("CashRegisterClass"));
        CashRegisterClass->resize(1093, 708);
        verticalLayout_2 = new QVBoxLayout(CashRegisterClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_scaner = new QLabel(CashRegisterClass);
        label_scaner->setObjectName(QString::fromUtf8("label_scaner"));

        horizontalLayout_2->addWidget(label_scaner);

        label_status = new QLabel(CashRegisterClass);
        label_status->setObjectName(QString::fromUtf8("label_status"));

        horizontalLayout_2->addWidget(label_status);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pb_Intery = new QPushButton(CashRegisterClass);
        pb_Intery->setObjectName(QString::fromUtf8("pb_Intery"));
        pb_Intery->setMinimumSize(QSize(83, 53));
        pb_Intery->setSizeIncrement(QSize(0, 0));

        verticalLayout->addWidget(pb_Intery);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pb_calculate = new QPushButton(CashRegisterClass);
        pb_calculate->setObjectName(QString::fromUtf8("pb_calculate"));
        pb_calculate->setMinimumSize(QSize(83, 53));

        verticalLayout->addWidget(pb_calculate);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        pb_log = new QPushButton(CashRegisterClass);
        pb_log->setObjectName(QString::fromUtf8("pb_log"));
        pb_log->setMinimumSize(QSize(83, 53));

        verticalLayout->addWidget(pb_log);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        horizontalLayout_3->addLayout(verticalLayout);

        stackedWidget = new QStackedWidget(CashRegisterClass);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        horizontalLayout_3->addWidget(stackedWidget);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(CashRegisterClass);

        QMetaObject::connectSlotsByName(CashRegisterClass);
    } // setupUi

    void retranslateUi(QWidget *CashRegisterClass)
    {
        CashRegisterClass->setWindowTitle(QApplication::translate("CashRegisterClass", "CashRegister", nullptr));
        label_scaner->setText(QApplication::translate("CashRegisterClass", "\346\211\253\347\240\201\346\236\252\347\212\266\346\200\201:", nullptr));
        label_status->setText(QApplication::translate("CashRegisterClass", "\346\234\252\350\277\236\346\216\245", nullptr));
        pb_Intery->setText(QApplication::translate("CashRegisterClass", "\345\205\245\345\272\223", nullptr));
        pb_calculate->setText(QApplication::translate("CashRegisterClass", "\347\273\223\347\256\227", nullptr));
        pb_log->setText(QApplication::translate("CashRegisterClass", "\346\237\245\347\234\213\345\207\272\345\272\223\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CashRegisterClass: public Ui_CashRegisterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASHREGISTER_H
