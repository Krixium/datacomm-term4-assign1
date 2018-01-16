/********************************************************************************
** Form generated from reading UI file 'assign1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGN1_H
#define UI_ASSIGN1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_assign1Class
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_ip_lookup;
    QPushButton *pushButton_hostname_lookup;
    QPushButton *pushButton_service_lookup;
    QPushButton *pushButton_port_lookup;
    QLabel *label_result;

    void setupUi(QMainWindow *assign1Class)
    {
        if (assign1Class->objectName().isEmpty())
            assign1Class->setObjectName(QStringLiteral("assign1Class"));
        assign1Class->resize(471, 78);
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(12);
        assign1Class->setFont(font);
        assign1Class->setCursor(QCursor(Qt::ArrowCursor));
        centralWidget = new QWidget(assign1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 449, 56));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_ip_lookup = new QPushButton(widget);
        pushButton_ip_lookup->setObjectName(QStringLiteral("pushButton_ip_lookup"));
        pushButton_ip_lookup->setFont(font);

        horizontalLayout->addWidget(pushButton_ip_lookup);

        pushButton_hostname_lookup = new QPushButton(widget);
        pushButton_hostname_lookup->setObjectName(QStringLiteral("pushButton_hostname_lookup"));
        pushButton_hostname_lookup->setFont(font);

        horizontalLayout->addWidget(pushButton_hostname_lookup);

        pushButton_service_lookup = new QPushButton(widget);
        pushButton_service_lookup->setObjectName(QStringLiteral("pushButton_service_lookup"));
        pushButton_service_lookup->setFont(font);

        horizontalLayout->addWidget(pushButton_service_lookup);

        pushButton_port_lookup = new QPushButton(widget);
        pushButton_port_lookup->setObjectName(QStringLiteral("pushButton_port_lookup"));
        pushButton_port_lookup->setFont(font);

        horizontalLayout->addWidget(pushButton_port_lookup);


        verticalLayout->addLayout(horizontalLayout);

        label_result = new QLabel(widget);
        label_result->setObjectName(QStringLiteral("label_result"));
        label_result->setFont(font);

        verticalLayout->addWidget(label_result);

        assign1Class->setCentralWidget(centralWidget);

        retranslateUi(assign1Class);

        QMetaObject::connectSlotsByName(assign1Class);
    } // setupUi

    void retranslateUi(QMainWindow *assign1Class)
    {
        assign1Class->setWindowTitle(QApplication::translate("assign1Class", "Network Lookup Tool", Q_NULLPTR));
        pushButton_ip_lookup->setText(QApplication::translate("assign1Class", "Lookup IP", Q_NULLPTR));
        pushButton_hostname_lookup->setText(QApplication::translate("assign1Class", "Lookup Hostname", Q_NULLPTR));
        pushButton_service_lookup->setText(QApplication::translate("assign1Class", "Service Lookup", Q_NULLPTR));
        pushButton_port_lookup->setText(QApplication::translate("assign1Class", "Port Lookup", Q_NULLPTR));
        label_result->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class assign1Class: public Ui_assign1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGN1_H
