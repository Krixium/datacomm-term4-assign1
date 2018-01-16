#include "HostnameLookupDialog.h"

HostnameLookupDialog::HostnameLookupDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_ok, &QPushButton::pressed, this, &HostnameLookupDialog::okayButtonPressed);
}

void HostnameLookupDialog::okayButtonPressed()
{
	emit signalIpAddressEntered(ui.lineEdit->text());
	ui.lineEdit->clear();
	hide();
}