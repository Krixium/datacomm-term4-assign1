/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: HostNameLookupDialog.cpp - An application that performs network lookups.
--
-- PROGRAM:		assign1 
--
-- FUNCTIONS:
--				HostNameLookupDialog(void)
--				void okayButtonPressed(void)
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang 
--
-- PROGRAMMER:	Benny Wang 
--
-- NOTES:
-- This is the dialog box for the user to enter an IP address and a protocol so that the host name can be looked up.
----------------------------------------------------------------------------------------------------------------------*/
#include "HostNameLookupDialog.h"

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	HostNameLookupDialog
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	HostNameLookupDialog HostNameLookupDialog (QWidget *parent)
--					QWidget *parent: A pointer to the parent QWidget.
--
-- RETURNS:		HostNameLookupDialog object 
--
-- NOTES:
-- Creates the UI for the dialog box and connects signal/slot pairs specific to itself.
----------------------------------------------------------------------------------------------------------------------*/
HostNameLookupDialog::HostNameLookupDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_ok, &QPushButton::pressed, this, &HostNameLookupDialog::okayButtonPressed);
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
void HostNameLookupDialog::okayButtonPressed()
{
	emit signalIpAddressEntered(ui.lineEdit->text());
	ui.lineEdit->clear();
	hide();
}