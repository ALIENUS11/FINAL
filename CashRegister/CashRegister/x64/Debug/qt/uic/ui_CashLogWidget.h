/********************************************************************************
** Form generated from reading UI file 'CashLogWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASHLOGWIDGET_H
#define UI_CASHLOGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CashLogWidgetClass
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *CashLogWidgetClass)
    {
        if (CashLogWidgetClass->objectName().isEmpty())
            CashLogWidgetClass->setObjectName(QString::fromUtf8("CashLogWidgetClass"));
        CashLogWidgetClass->resize(600, 400);
        verticalLayout = new QVBoxLayout(CashLogWidgetClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(CashLogWidgetClass);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(CashLogWidgetClass);

        QMetaObject::connectSlotsByName(CashLogWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *CashLogWidgetClass)
    {
        CashLogWidgetClass->setWindowTitle(QApplication::translate("CashLogWidgetClass", "CashLogWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CashLogWidgetClass: public Ui_CashLogWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASHLOGWIDGET_H
