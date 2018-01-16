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

const string WinsockManager::LookupIpByHostname(const char * hostname)
{
	struct hostent *hp;

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

const string WinsockManager::LookupHostNameByIp(const char * ipAddress)
{
	int		a;
	struct	hostent *hp;
	struct	in_addr my_addr, *addr_p;
	char	**p;
	char	ip_address[256];
	string ss;

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
		for (p = hp->h_addr_list; *p != 0; p++)
		{
			struct in_addr in;
			char **q;

			memcpy(&in.s_addr, *p, sizeof (in.s_addr));
			ss += string("Host Name: ") + string(hp->h_name);
			ss += string("\nAliases:\n");

			for (q = hp->h_aliases; *q != 0; q++)
			{
				ss += string("\t") + string(*q) + string("\n");
			}
		}

		return ss;
	}
}

const string WinsockManager::LookupServiceByPort(const int port, const char * protocol)
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