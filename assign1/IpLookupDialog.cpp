/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: IpLookupDialog.cpp - An application that performs network lookups.
--
-- PROGRAM:		assign1 
--
-- FUNCTIONS:
--				IpLookupDialog(void)
--				void okayButtonPressed(void)
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang 
--
-- PROGRAMMER:	Benny Wang 
--
-- NOTES:
-- This is the dialog box for the user to enter a host name so that the IP address can be looked up.
----------------------------------------------------------------------------------------------------------------------*/
#include "IpLookupDialog.h"

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	IpLookupDialog
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	IpLookupDialog IpLookupDialog (QWidget *parent)
--					QWidget *parent: A pointer to the parent QWidget.
--
-- RETURNS:		IpLookupDialog object 
--
-- NOTES:
-- Creates the UI for the dialog box and connects signal/slot pairs specific to itself.
----------------------------------------------------------------------------------------------------------------------*/
IpLookupDialog::IpLookupDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_ok, &QPushButton::pressed, this, &IpLookupDialog::okayButtonPressed);
	connect(ui.pushButton_cancel, &QPushButton::pressed, this, &QWidget::hide);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	okayButtonPressed
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	void okayButtonPressed (void)
--
-- RETURNS:		void
--
-- NOTES:
-- When okay is pressed, this slot emits a signal with the current information entered into this dialog box, clears
-- all input fields and hides the dialog box.
----------------------------------------------------------------------------------------------------------------------*/
void IpLookupDialog::okayButtonPressed()
{
	emit signalHostnameEntered(ui.lineEdit_input->text());
	ui.lineEdit_input->clear();
	hide();
}