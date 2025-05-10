/********************************************************************************
** Form generated from reading UI file 'InventoryWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYWIDGET_H
#define UI_INVENTORYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InventoryWidgetClass
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *InventoryWidgetClass)
    {
        if (InventoryWidgetClass->objectName().isEmpty())
            InventoryWidgetClass->setObjectName(QString::fromUtf8("InventoryWidgetClass"));
        InventoryWidgetClass->resize(739, 584);
        verticalLayout = new QVBoxLayout(InventoryWidgetClass);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(InventoryWidgetClass);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(InventoryWidgetClass);

        QMetaObject::connectSlotsByName(InventoryWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *InventoryWidgetClass)
    {
        InventoryWidgetClass->setWindowTitle(QApplication::translate("InventoryWidgetClass", "InventoryWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InventoryWidgetClass: public Ui_InventoryWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYWIDGET_H
