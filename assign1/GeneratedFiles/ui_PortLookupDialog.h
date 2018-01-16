/********************************************************************************
** Form generated from reading UI file 'PortLookupDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTLOOKUPDIALOG_H
#define UI_PORTLOOKUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Port_Dialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_service;
    QLineEdit *lineEdit_service;
    QLabel *label_protocol;
    QLineEdit *lineEdit_protocol;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(460, 114);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        Dialog->setFont(font);
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 441, 95));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_service = new QLabel(widget);
        label_service->setObjectName(QStringLiteral("label_service"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_service);

        lineEdit_service = new QLineEdit(widget);
        lineEdit_service->setObjectName(QStringLiteral("lineEdit_service"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_service);

        label_protocol = new QLabel(widget);
        label_protocol->setObjectName(QStringLiteral("label_protocol"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_protocol);

        lineEdit_protocol = new QLineEdit(widget);
        lineEdit_protocol->setObjectName(QStringLiteral("lineEdit_protocol"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_protocol);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_ok = new QPushButton(widget);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));

        horizontalLayout->addWidget(pushButton_ok);

        pushButton_cancel = new QPushButton(widget);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout->addWidget(pushButton_cancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label_service->setText(QApplication::translate("Dialog", "Service:", Q_NULLPTR));
        label_protocol->setText(QApplication::translate("Dialog", "Protocol:", Q_NULLPTR));
        pushButton_ok->setText(QApplication::translate("Dialog", "OK", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("Dialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Port: public Ui_Port_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTLOOKUPDIALOG_H
