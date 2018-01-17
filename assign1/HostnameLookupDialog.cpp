#include "HostNameLookupDialog.h"

HostNameLookupDialog::HostNameLookupDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_ok, &QPushButton::pressed, this, &HostNameLookupDialog::okayButtonPressed);
}

void HostNameLookupDialog::okayButtonPressed()
{
	emit signalIpAddressEntered(ui.lineEdit->text());
	ui.lineEdit->clear();
	hide();
}