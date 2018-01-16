#include "assign1.h"

#include <QDebug>

assign1::assign1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ipLookupDialog = new IpLookupDialog(this);
	hostnameLookupDialog = new HostnameLookupDialog(this);
	serviceLookupDialog = new ServiceLookupDialog(this);
	portLookupDialog = new PortLookupDialog(this);
	winsockManager = new WinsockManager();

	initConnections();
}

assign1::~assign1()
{
	delete ipLookupDialog;
	delete hostnameLookupDialog;
	delete serviceLookupDialog;
	delete portLookupDialog;
	delete winsockManager;
}

void assign1::initConnections()
{
	connect(ui.pushButton_ip_lookup, &QPushButton::pressed, this, &assign1::lookupIpPressed);
	connect(ui.pushButton_hostname_lookup, &QPushButton::pressed, this, &assign1::lookupHostnamePressed);
	connect(ui.pushButton_service_lookup, &QPushButton::pressed, this, &assign1::lookupServicePressed);
	connect(ui.pushButton_port_lookup, &QPushButton::pressed, this, &assign1::lookupPortPressed);

	connect(ipLookupDialog, &IpLookupDialog::signalHostnameEntered, this, &assign1::hostnameReceived);
	connect(hostnameLookupDialog, &HostnameLookupDialog::signalIpAddressEntered, this, &assign1::ipReceived);
	connect(serviceLookupDialog, &ServiceLookupDialog::signalPortInfoEntered, this, &assign1::portReceived);
	connect(portLookupDialog, &PortLookupDialog::signalServiceInfoEntered, this, &assign1::serviceReceived);
}

void assign1::displayTextOnLabel(const QString text)
{
	ui.label_result->setText(text);
}

void assign1::lookupIpPressed()
{
	ipLookupDialog->show();
}

void assign1::lookupHostnamePressed()
{
	hostnameLookupDialog->show();
}

void assign1::lookupServicePressed()
{
	serviceLookupDialog->show();
}

void assign1::lookupPortPressed()
{
	portLookupDialog->show();
}

void assign1::hostnameReceived(const QString hostname)
{
	const char * ipAddress = winsockManager->LookupIpByHostname(hostname.toStdString().c_str());

	if (ipAddress == "")
	{
		displayTextOnLabel("Error: IP Address could not be found.");
	}
	else
	{
		QString message = "The IP address of " + hostname + " is " + ipAddress;
		displayTextOnLabel(message);
	}
}

void assign1::ipReceived(const QString ipAddress)
{
	const char * hostname = winsockManager->LookupHostnameByIp(ipAddress.toStdString().c_str());

	if (hostname == "")
	{
		displayTextOnLabel("Error: Hostname could not be found.");
	}
	else
	{
		QString message = "The hostname for " + ipAddress + " is " + hostname + ".";
		displayTextOnLabel(message);
	}
}

void assign1::portReceived(const QString port, const QString protocol)
{
	const char * service = winsockManager->LookupServiceByPort(port.toInt(), protocol.toUpper().toStdString().c_str());

	if (service[0] == '\0')
	{
		displayTextOnLabel("Error: Service cound not be found.");
	}
	else
	{
		QString message = "Port " + port + "/" + protocol.toUpper() + " is used for " + QString(service).toUpper() + ".";
		displayTextOnLabel(message);
	}
}

void assign1::serviceReceived(const QString service, const QString protocol)
{
	const short port = winsockManager->LookupPortByService(service.toUpper().toStdString().c_str(), protocol.toUpper().toStdString().c_str());

	if (port == -1)
	{
		displayTextOnLabel("Error: Port could not be found.");
	}
	else
	{
		QString message = service.toUpper() + " using " + protocol.toUpper() + " uses port " + QString::number(port) + ".";
		displayTextOnLabel(message);
	}
}