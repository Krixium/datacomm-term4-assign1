#pragma once

#pragma comment(lib, "ws2_32.lib")

#include <string>
#include <winsock2.h>

using namespace std;

class WinsockManager
{
public:
	WinsockManager();
	~WinsockManager();

	const string LookupIpByHostName(const char * hostname);
	const string LookupHostNameByIp(const char * ipAddress);
	const string LookupServiceByPort(const int port, const char * protocol);
	const short LookupPortByService(const char * service, const char * protocol);

private:

	WORD wVersionRequested;
	WSADATA wsaData;
};