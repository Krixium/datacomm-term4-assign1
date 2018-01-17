#pragma once

#include <QtWidgets/QDialog>
#include "ui_HostnameLookupDialog.h"

class HostNameLookupDialog : public QDialog
{
	Q_OBJECT

public:
	HostNameLookupDialog(QWidget *parent = Q_NULLPTR);

private:
	Ui::Dialog_HostName ui;

private slots:
	void okayButtonPressed();

signals:
	void signalIpAddressEntered(const QString ipAddress);
};