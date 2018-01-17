/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: PortLookupDialog.cpp - An application that performs network lookups.
--
-- PROGRAM:		assign1 
--
-- FUNCTIONS:
--				PortLookupDialog(void)
--				void okayButtonPressed(void)
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang 
--
-- PROGRAMMER:	Benny Wang 
--
-- NOTES:
-- This is the dialog box for the user to enter a service and a protocol so that the service can be looked up.
----------------------------------------------------------------------------------------------------------------------*/
#include "PortLookupDialog.h"

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	PortLookupDialog
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	PortLookupDialog PortLookupDialog (QWidget *parent)
--					QWidget *parent: A pointer to the parent QWidget.
--
-- RETURNS:		PortLookupDialog object 
--
-- NOTES:
-- Creates the UI for the dialog box and connects signal/slot pairs specific to itself.
----------------------------------------------------------------------------------------------------------------------*/
PortLookupDialog::PortLookupDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_ok, &QPushButton::pressed, this, &PortLookupDialog::okayButtonPressed);
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
void PortLookupDialog::okayButtonPressed()
{
	emit signalServiceInfoEntered(ui.lineEdit_service->text(), ui.lineEdit_protocol->text());
	ui.lineEdit_service->clear();
	ui.lineEdit_protocol->clear();
	hide();
}