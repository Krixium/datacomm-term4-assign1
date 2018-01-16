#pragma once

#include <QtWidgets/QDialog>
#include "ui_ServiceLookupDialog.h"

class ServiceLookupDialog : public QDialog
{
	Q_OBJECT

public:
	ServiceLookupDialog(QWidget *parent = Q_NULLPTR);

private:
	Ui::Dialog_Service ui;

private slots:
	void okayButtonPressed();

signals:
	void signalPortInfoEntered(const QString portNumber, const QString protocol);
};
