#pragma once

#include <QtWidgets/QDialog>
#include "ui_IpLookupDialog.h"

class IpLookupDialog : public QDialog
{
	Q_OBJECT

public:
	IpLookupDialog(QWidget *parent = Q_NULLPTR);

private:
	Ui::Dialog_Ip ui;

private slots:
	void okayButtonPressed();

signals:
	void signalHostnameEntered(const QString hostname);
};