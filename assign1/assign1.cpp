#include "assign1.h"

assign1::assign1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ipLookupDialog = new IpLookupDialog(this);
	hostnameLookupDialog = new HostnameLookupDialog(this);
	serviceLookupDialog = new ServiceLookupDialog(this);
	portLookupDialog = new PortLookupDialog(this);

	initConnections();
}

assign1::~assign1()
{
	delete ipLookupDialog;
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
	displayTextOnLabel(hostname);
}

void assign1::ipReceived(const QString ipAddress)
{
	displayTextOnLabel(ipAddress);
}

void assign1::portReceived(const QString port, const QString protocol)
{
	displayTextOnLabel(port + " " + protocol);
}

void assign1::serviceReceived(const QString service, const QString protocol)
{
	displayTextOnLabel(service + " " + protocol);
}