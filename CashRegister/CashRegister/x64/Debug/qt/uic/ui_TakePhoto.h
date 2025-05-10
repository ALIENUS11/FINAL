/********************************************************************************
** Form generated from reading UI file 'TakePhoto.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAKEPHOTO_H
#define UI_TAKEPHOTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TakePhotoClass
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *TakePhotoClass)
    {
        if (TakePhotoClass->objectName().isEmpty())
            TakePhotoClass->setObjectName(QString::fromUtf8("TakePhotoClass"));
        TakePhotoClass->resize(839, 592);
        horizontalLayout = new QHBoxLayout(TakePhotoClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(TakePhotoClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        pushButton = new QPushButton(TakePhotoClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 51));

        horizontalLayout->addWidget(pushButton);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 1);

        retranslateUi(TakePhotoClass);

        QMetaObject::connectSlotsByName(TakePhotoClass);
    } // setupUi

    void retranslateUi(QWidget *TakePhotoClass)
    {
        TakePhotoClass->setWindowTitle(QApplication::translate("TakePhotoClass", "TakePhoto", nullptr));
        label->setText(QString());
        pushButton->setText(QApplication::translate("TakePhotoClass", "\346\213\215\347\205\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TakePhotoClass: public Ui_TakePhotoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAKEPHOTO_H
