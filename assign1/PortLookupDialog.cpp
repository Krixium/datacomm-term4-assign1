#include "PortLookupDialog.h"

PortLookupDialog::PortLookupDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_ok, &QPushButton::pressed, this, &PortLookupDialog::okayButtonPressed);
	connect(ui.pushButton_cancel, &QPushButton::pressed, this, &QWidget::hide);
}

void PortLookupDialog::okayButtonPressed()
{
	emit signalServiceInfoEntered(ui.lineEdit_service->text(), ui.lineEdit_protocol->text());
	ui.lineEdit_service->clear();
	ui.lineEdit_protocol->clear();
	hide();
}