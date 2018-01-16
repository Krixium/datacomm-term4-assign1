#include "IpLookupDialog.h"

IpLookupDialog::IpLookupDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_ok, &QPushButton::pressed, this, &IpLookupDialog::okayButtonPressed);
	connect(ui.pushButton_cancel, &QPushButton::pressed, this, &QWidget::hide);
}

void IpLookupDialog::okayButtonPressed()
{
	emit signalHostnameEntered(ui.lineEdit_input->text());
	ui.lineEdit_input->clear();
	hide();
}