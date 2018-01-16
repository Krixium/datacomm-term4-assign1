#include "ServiceLookupDialog.h"

ServiceLookupDialog::ServiceLookupDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_ok, &QPushButton::pressed, this, &ServiceLookupDialog::okayButtonPressed);
	connect(ui.pushButton_cancel, &QPushButton::pressed, this, &QWidget::hide);
}

void ServiceLookupDialog::okayButtonPressed()
{
	emit signalPortInfoEntered(ui.lineEdit_port->text(), ui.lineEdit_protocol->text());
	ui.lineEdit_port->clear();
	ui.lineEdit_protocol->clear();
	hide();
}