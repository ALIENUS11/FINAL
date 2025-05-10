/********************************************************************************
** Form generated from reading UI file 'CheckoutWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKOUTWIDGET_H
#define UI_CHECKOUTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckoutWidgetClass
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_price;
    QPushButton *pushButton;

    void setupUi(QWidget *CheckoutWidgetClass)
    {
        if (CheckoutWidgetClass->objectName().isEmpty())
            CheckoutWidgetClass->setObjectName(QString::fromUtf8("CheckoutWidgetClass"));
        CheckoutWidgetClass->resize(773, 564);
        verticalLayout = new QVBoxLayout(CheckoutWidgetClass);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        tableWidget = new QTableWidget(CheckoutWidgetClass);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setBold(true);
        font.setWeight(75);
        tableWidget->setFont(font);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CheckoutWidgetClass);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(22);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        label_price = new QLabel(CheckoutWidgetClass);
        label_price->setObjectName(QString::fromUtf8("label_price"));
        label_price->setFont(font1);

        horizontalLayout->addWidget(label_price);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        horizontalLayout_2->addLayout(horizontalLayout);

        pushButton = new QPushButton(CheckoutWidgetClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalLayout_2->setStretch(0, 7);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CheckoutWidgetClass);

        QMetaObject::connectSlotsByName(CheckoutWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *CheckoutWidgetClass)
    {
        CheckoutWidgetClass->setWindowTitle(QApplication::translate("CheckoutWidgetClass", "CheckoutWidget", nullptr));
        label->setText(QApplication::translate("CheckoutWidgetClass", "\346\200\273\344\273\267:", nullptr));
        label_price->setText(QString());
        pushButton->setText(QApplication::translate("CheckoutWidgetClass", "\345\207\272\345\272\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckoutWidgetClass: public Ui_CheckoutWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUTWIDGET_H
