/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: assign1.cpp - An application that performs network lookups.
--
-- PROGRAM:		assign1 
--
-- FUNCTIONS:
--				assign1(void)
--				~assign1(void)
--				void initConnections(void)
--				void displayText(const QString text)
--				void lookupIpPressed(void)
--				void lookupHostNamePressed(void)
--				void lookupServicePressed(void)
--				void lookupPortPressed(void)
--				void hostNameReceived(const QString hostname)
--				void ipReceived(const QString ipAddress)
--				void portReceived(const QString port, const QString protocol)
--				void serviceReceived(const QString service, const QString protocol)
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang 
--
-- PROGRAMMER:	Benny Wang 
--
-- NOTES:
-- This is the main section of the progarm. This is where the constructor for the main window is implemented and where
-- the major windows of the program have their signals and slots connected. The main role of this class is to act as a
-- controller to the other parts of the program.
----------------------------------------------------------------------------------------------------------------------*/
#include "assign1.h"

#include <string>

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	assign1
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	assign1 assign1 (QWidget *parent)
--					QWidget *parent: A pointer to the parent QWidget.
--
-- RETURNS:		assign1 object 
--
-- NOTES:
-- The constructor for the main widget of the program. This is where all dialog windows are instantiated and most
-- signals and slots are connected.
----------------------------------------------------------------------------------------------------------------------*/
assign1::assign1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ipLookupDialog = new IpLookupDialog(this);
	hostNameLookupDialog = new HostNameLookupDialog(this);
	serviceLookupDialog = new ServiceLookupDialog(this);
	portLookupDialog = new PortLookupDialog(this);
	winsockManager = new WinsockManager();

	connect(ui.pushButton_ip_lookup, &QPushButton::pressed, this, &assign1::lookupIpPressed);
	connect(ui.pushButton_hostname_lookup, &QPushButton::pressed, this, &assign1::lookupHostNamePressed);
	connect(ui.pushButton_service_lookup, &QPushButton::pressed, this, &assign1::lookupServicePressed);
	connect(ui.pushButton_port_lookup, &QPushButton::pressed, this, &assign1::lookupPortPressed);

	connect(ipLookupDialog, &IpLookupDialog::signalHostnameEntered, this, &assign1::hostNameReceived);
	connect(hostNameLookupDialog, &HostNameLookupDialog::signalIpAddressEntered, this, &assign1::ipReceived);
	connect(serviceLookupDialog, &ServiceLookupDialog::signalPortInfoEntered, this, &assign1::portReceived);
	connect(portLookupDialog, &PortLookupDialog::signalServiceInfoEntered, this, &assign1::serviceReceived);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	~assign1
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	void ~assign1 (void)
--
-- RETURNS:		void
--
-- NOTES:
-- The deconstructor of the main widget of the program. All dialog boxes are deleted here.
----------------------------------------------------------------------------------------------------------------------*/
assign1::~assign1()
{
	delete ipLookupDialog;
	delete hostNameLookupDialog;
	delete serviceLookupDialog;
	delete portLookupDialog;
	delete winsockManager;
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	displayText
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	void dispayText (const QString text)
--					const QString text: The text to be dispalyed.
--
-- RETURNS:		void
--
-- NOTES:
-- Takes a given QString input and displays it to the screen. This function exists to abstarct the exact way text
-- is displayed to the user.
----------------------------------------------------------------------------------------------------------------------*/
void assign1::displayText(const QString text)
{
	ui.plainTextEdit->appendPlainText(text);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	lookupIpPressed
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	void lookupIpPressed (void)
--
-- RETURNS:		void
--
-- NOTES:
-- This is a Qt slot.
--
-- This slot is triggered when the button to look up an IP is pressed. This function displays a pop-up box for the user
-- to enter an IP to look up.
----------------------------------------------------------------------------------------------------------------------*/
void assign1::lookupIpPressed()
{
	ipLookupDialog->show();
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	lookupHostNamePressed
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	void lookupHostNamePressed (void)
--
-- RETURNS:		void
--
-- NOTES:
-- This is a Qt slot.
--
-- This slot is triggered when the button to look up an host name is pressed. This function displays a pop-up box 
-- for the user to enter a host name to look up.
----------------------------------------------------------------------------------------------------------------------*/
void assign1::lookupHostNamePressed()
{
	hostNameLookupDialog->show();
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	lookupServicePressed
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	void lookupServicePressed (void)
--
-- RETURNS:		void
--
-- NOTES:
-- This is a Qt slot.
--
-- This slot is triggered when the button to look up a service is pressed. This function displays a pop-up box for 
-- the user to enter a service/protocol pair to look up.
----------------------------------------------------------------------------------------------------------------------*/
void assign1::lookupServicePressed()
{
	serviceLookupDialog->show();
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	lookupPortPressed
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	void lookupPortPressed (void)
--
-- RETURNS:		void
--
-- NOTES:
-- This is a Qt slot.
--
-- This slot is triggered when the button to look up a port is pressed. This function displays a pop-up box for the user
-- to enter an port/protocol pair to look up.
----------------------------------------------------------------------------------------------------------------------*/
void assign1::lookupPortPressed()
{
	portLookupDialog->show();
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	hostNameReceived
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	void hostNameReceived (const QString hostName)
--					const QString hostName: The host name to be looked up.
--
-- RETURNS:		void
--
-- NOTES:
-- This is a Qt slot.
--
-- When a user enters a host name in the dialog box this slot is triggered. It takes the given host name and passes it
-- to the winsock wrapper object to perform an IP lookup. If something is returned, it is displayed, otherwise an error
-- message is displayed.
----------------------------------------------------------------------------------------------------------------------*/
void assign1::hostNameReceived(const QString hostName)
{
	const string ipAddress = winsockManager->LookupIpByHostName(hostName.toStdString().c_str());

	if (ipAddress[0] == '\0')
	{
		displayText("Error: IP Address could not be found.");
	}
	else
	{
		QString message = "The IP address of " + hostName + " are " + QString::fromStdString(ipAddress);
		displayText(message);
	}
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	ipReceived
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	void ipReceived (const QString ipAddress)
--					const QString ipAddress: The IP to be looked up.
--
-- RETURNS:		void
--
-- NOTES:
-- This is a Qt slot.
--
-- When a user enters an IP address in the dialog box this slot is triggered. It takes the given IP address and 
-- passes it to the winsock wrapper object to perform a host name lookup. If something is returned, it is displayed,
-- otherwise an error message is displayed.
----------------------------------------------------------------------------------------------------------------------*/
void assign1::ipReceived(const QString ipAddress)
{
	const string hostname = winsockManager->LookupHostNameByIp(ipAddress.toStdString().c_str());

	if (hostname[0] == '\0')
	{
		displayText("Error: Host Name could not be found.");
	}
	else
	{
		QString message = "The host names for " + ipAddress + " are\n" + QString::fromStdString(hostname);
		displayText(message);
	}
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	portReceived
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	void portReceived (const QString port, const QString protocol)
--					const QString port: The port to be looked up.
--					const QString protocol: The protocol to be looked up.
--
-- RETURNS:		void
--
-- NOTES:
-- This is a Qt slot.
--
-- When a user enters a port/protocol pair in the dialog box this slot is triggered. It takes the given port/protocol 
-- pair and passes it  to the winsock wrapper object to perform an service lookup. If something is returned, it is 
-- displayed, otherwise an error message is displayed.
----------------------------------------------------------------------------------------------------------------------*/
void assign1::portReceived(const QString port, const QString protocol)
{
	const string service = winsockManager->LookupServiceByPort(port.toInt(), protocol.toUpper().toStdString().c_str());

	if (service[0] == '\0')
	{
		displayText("Error: Service cound not be found.");
	}
	else
	{
		QString message = "Port " + port + "/" + protocol.toUpper() + " is used for " + QString::fromStdString(service).toUpper();
		displayText(message);
	}
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	serviceReceived
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	void serviceReceived (const QString service, const QString protocol)
--					const QString service: The service to be looked up.
--					const QString protocol: The protocol to be looked up.
--
-- RETURNS:		void
--
-- NOTES:
-- This is a Qt slot.
--
-- When a user enters a service/protocol pair in the dialog box this slot is triggered. It takes the given 
-- servce/protocol pair and passes it to the winsock wrapper object to perform an port lookup. If something is 
-- returned, it is displayed, otherwise an error message is displayed.
----------------------------------------------------------------------------------------------------------------------*/
void assign1::serviceReceived(const QString service, const QString protocol)
{
	const short port = winsockManager->LookupPortByService(service.toUpper().toStdString().c_str(), protocol.toUpper().toStdString().c_str());

	if (port == -1)
	{
		displayText("Error: Port could not be found.");
	}
	else
	{
		QString message = service.toUpper() + " using " + protocol.toUpper() + " uses port " + QString::number(port);
		displayText(message);
	}
}