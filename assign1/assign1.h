#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_assign1.h"

#include "HostnameLookupDialog.h"
#include "IpLookupDialog.h"
#include "PortLookupDialog.h"
#include "ServiceLookupDialog.h"
#include "WinsockManager.h"

class assign1 : public QMainWindow
{
	Q_OBJECT

public:
	assign1(QWidget *parent = Q_NULLPTR);
	~assign1();

private:
	Ui::assign1Class ui;
	IpLookupDialog* ipLookupDialog;
	HostnameLookupDialog* hostnameLookupDialog;
	ServiceLookupDialog* serviceLookupDialog;
	PortLookupDialog* portLookupDialog;
	WinsockManager* winsockManager;

	void initConnections();
	void displayTextOnLabel(const QString text);

private slots:
	void lookupIpPressed();
	void lookupHostnamePressed();
	void lookupServicePressed();
	void lookupPortPressed();

	void hostnameReceived(const QString hostname);
	void ipReceived(const QString ipAddress);
	void portReceived(const QString portNumber, const QString protocol);
	void serviceReceived(const QString service, const QString protocol);
};
