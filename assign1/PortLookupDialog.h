#pragma once

#include <QtWidgets/QDialog>
#include "ui_PortLookupDialog.h"

class PortLookupDialog : public QDialog
{
	Q_OBJECT

public:
	PortLookupDialog(QWidget *parent = Q_NULLPTR);

private:
	Ui::Dialog_Port ui;

private slots:
	void okayButtonPressed();

signals:
	void signalServiceInfoEntered(const QString serviceName, const QString protocol);
};
