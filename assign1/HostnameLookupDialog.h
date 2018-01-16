#pragma once

#include <QtWidgets/QDialog>
#include "ui_HostnameLookupDialog.h"

class HostnameLookupDialog : public QDialog
{
	Q_OBJECT

public:
	HostnameLookupDialog(QWidget *parent = Q_NULLPTR);

private:
	Ui::Dialog_Hostname ui;

private slots:
	void okayButtonPressed();

signals:
	void signalIpAddressEntered(const QString ipAddress);
};