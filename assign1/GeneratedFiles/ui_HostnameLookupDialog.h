/********************************************************************************
** Form generated from reading UI file 'HostnameLookupDialogem7172.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef HOSTNAMELOOKUPDIALOGEM7172_H
#define HOSTNAMELOOKUPDIALOGEM7172_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hostname_Dialog
{
public:
	QWidget * widget;
	QVBoxLayout *verticalLayout;
	QHBoxLayout *horizontalLayout;
	QLabel *label_ip;
	QLineEdit *lineEdit;
	QHBoxLayout *horizontalLayout_2;
	QPushButton *pushButton_ok;
	QPushButton *pushButton_cancel;

	void setupUi(QDialog *Dialog)
	{
		if (Dialog->objectName().isEmpty())
			Dialog->setObjectName(QStringLiteral("Dialog"));
		Dialog->resize(460, 84);
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
		widget->setGeometry(QRect(10, 10, 441, 64));
		verticalLayout = new QVBoxLayout(widget);
		verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
		verticalLayout->setContentsMargins(0, 0, 0, 0);
		horizontalLayout = new QHBoxLayout();
		horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
		label_ip = new QLabel(widget);
		label_ip->setObjectName(QStringLiteral("label_ip"));

		horizontalLayout->addWidget(label_ip);

		lineEdit = new QLineEdit(widget);
		lineEdit->setObjectName(QStringLiteral("lineEdit"));

		horizontalLayout->addWidget(lineEdit);


		verticalLayout->addLayout(horizontalLayout);

		horizontalLayout_2 = new QHBoxLayout();
		horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
		pushButton_ok = new QPushButton(widget);
		pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));

		horizontalLayout_2->addWidget(pushButton_ok);

		pushButton_cancel = new QPushButton(widget);
		pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

		horizontalLayout_2->addWidget(pushButton_cancel);


		verticalLayout->addLayout(horizontalLayout_2);


		retranslateUi(Dialog);

		QMetaObject::connectSlotsByName(Dialog);
	} // setupUi

	void retranslateUi(QDialog *Dialog)
	{
		Dialog->setWindowTitle(QApplication::translate("Dialog", "Lookup Hostname", Q_NULLPTR));
		label_ip->setText(QApplication::translate("Dialog", "IP Address:", Q_NULLPTR));
		pushButton_ok->setText(QApplication::translate("Dialog", "OK", Q_NULLPTR));
		pushButton_cancel->setText(QApplication::translate("Dialog", "Cancel", Q_NULLPTR));
	} // retranslateUi

};

namespace Ui {
	class Dialog_Hostname : public Ui_Hostname_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // HOSTNAMELOOKUPDIALOGEM7172_H
