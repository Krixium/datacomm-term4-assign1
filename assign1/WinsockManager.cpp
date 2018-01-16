#include "WinsockManager.h"

WinsockManager::WinsockManager()
{
	wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &wsaData);
}

WinsockManager::~WinsockManager()
{
	WSACleanup();
}

const char * WinsockManager::LookupIpByHostname(const char * hostname)
{
	struct	hostent *hp;

	if ((hp = gethostbyname(hostname)) == NULL)
	{
		return "";
	}
	else
	{
		struct in_addr in;
		memcpy(&in.s_addr, hp->h_addr_list, sizeof(in.s_addr));
		return inet_ntoa(in);
	}
}

const char * WinsockManager::LookupHostnameByIp(const char * ipAddress)
{
	int		a;
	struct	hostent *hp;
	struct	in_addr my_addr, *addr_p;
	char	**p;
	char	ip_address[256];

	addr_p = (struct in_addr*)malloc(sizeof(struct in_addr));
	addr_p = &my_addr;

	if ((a = inet_addr(ipAddress)) == 0)
	{
		return "";
	}

	strcpy(ip_address, ipAddress);
	addr_p->s_addr = inet_addr(ip_address);


	hp = gethostbyaddr((char *)addr_p, PF_INET, sizeof(my_addr));

	if (hp == NULL)
	{
		return "";
	}
	else
	{
		return hp->h_name;
	}
}

const char * WinsockManager::LookupServiceByPort(const int port, const char * protocol)
{
	struct servent * sv;

	sv = getservbyport(htons(port), protocol);

	if (sv == NULL)
	{
		return "";
	}
	else
	{
		return sv->s_name;
	}
}

const short WinsockManager::LookupPortByService(const char * service, const char * protocol)
{
	struct servent * sv;

	sv = getservbyname(service, protocol);

	if (sv == NULL)
	{
		return -1;
	}
	else
	{
		return ntohs(sv->s_port);
	}
}