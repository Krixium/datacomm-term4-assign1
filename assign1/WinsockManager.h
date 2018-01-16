#pragma once

#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>

class WinsockManager
{
public:
	WinsockManager();
	~WinsockManager();

	const char * LookupIpByHostname(const char * hostname);
	const char * LookupHostnameByIp(const char * ipAddress);
	const char * LookupServiceByPort(const int port, const char * protocol);
	const short LookupPortByService(const char * service, const char * protocol);

private:

	WORD wVersionRequested;
	WSADATA wsaData;
};