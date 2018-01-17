/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: WinsockManager.cpp - An application that performs network lookups.
--
-- PROGRAM: assign1 
--
-- FUNCTIONS:
-- WinsockManager(void)
-- ~WinsockManager(void)
-- const std::string LookupHostNameByIp(const char * ipAddress)
-- const std::string LookupIpByHostName(const char * hostname)
-- const std::string LookupServiceByPort(const int port, const char * protocol)
-- const string WinsockManager::LookupServiceByPort(const int port, const char * protocol)
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang 
--
-- PROGRAMMER:	Benny Wang 
--
-- NOTES:
-- This class is a wrapper for the winsock API.
--
-- The winsock connection is openned in the constructor and closed in the deconstructor.
--
-- Currently the only winsock API calls that are support are:
--		- Search for host name with IP
--		- Search for IP with host name
--		- Search for port given a service and protocol
--		- Search for service given a port and protocol
----------------------------------------------------------------------------------------------------------------------*/
#include "WinsockManager.h"

#include <QDebug>

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	WinsockManager
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	WinsockManager WinsockManager (void)
--
-- RETURNS:		WinsockManager object 
--
-- NOTES:
-- Constructor for the Winsock wrapper object. The winsock connection is openned here.
----------------------------------------------------------------------------------------------------------------------*/
WinsockManager::WinsockManager()
{
	wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &wsaData);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	~WinsockManager
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	void ~WinsockManager (void)
--
-- RETURNS:		void.
--
-- NOTES:
-- Deconstructor for the Winsock wrapper object. The winsock connection is closed here. 
----------------------------------------------------------------------------------------------------------------------*/
WinsockManager::~WinsockManager()
{
	WSACleanup();
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	LookupIpByHostName
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	const string LookupIpByHostName (const char * hostname)
--					const char * hostname: The host name to look up.
--
-- RETURNS:		An IP address in dotted decimal format if no errors occured, nothing otherwise.
--
-- NOTES:
-- Takes a host name given by the user and looks up the related dotted decimal IP address using winsock and returns it.
-- The inputs are case sensitive.
----------------------------------------------------------------------------------------------------------------------*/
const string WinsockManager::LookupIpByHostName(const char * hostname)
{
	struct hostent *hp;
	char ** p;
	string s("");

	if ((hp = gethostbyname(hostname)) != NULL)
	{
		s += "\n";
		for (p = hp->h_addr_list; *p != 0; p++)
		{
			struct in_addr in;
			char **q;

			memcpy(&in.s_addr, *p, sizeof (in.s_addr));

			//printf("IP Address: %s\t Host Name: %s\n", inet_ntoa(in), hp->h_name);
			s += "\t" + string(inet_ntoa(in)) + "\n";
		}
	}

	return s;
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	LookupHostNameByIp
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	const string LookupHostNameByIp (const char * ipAddress)
--					const char * ipAddress: The ipAddress to look up.
--
-- RETURNS:		A host name and it's aliases if no errors occured, nothing otherwise.
--
-- NOTES:
-- Takes an IP Address given by the user and looks up the related host name using winsock and returns it. The inputs are
-- case sensitive.
----------------------------------------------------------------------------------------------------------------------*/
const string WinsockManager::LookupHostNameByIp(const char * ipAddress)
{
	int	a;
	struct hostent *hp;
	struct in_addr my_addr, *addr_p;
	char **p;
	char ip_address[256];
	string s;

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
			s += string("Host Name:\n\t") + string(hp->h_name);
			s += string("\nAliases:\n");

			for (q = hp->h_aliases; *q != 0; q++)
			{
				s += string("\t") + string(*q) + string("\n");
			}
		}

		return s;
	}
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	LookupServiceByPort
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	const string LookupServiceByPort (const int port, const char * protocol)
--					const int port: The port number.
--					const char * protocol: The protocol name.
--
-- RETURNS:		The name of the service that runs on port/protocol if no error occured, nothing otherwise.
--
-- NOTES:
-- Takes the given port and a protocol and looks up what service is being run on it and returns it. The input is case
-- sensitive.
----------------------------------------------------------------------------------------------------------------------*/
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

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	LookupPortByService
--
-- DATE:		January 16, 2018
--
-- DESIGNER:	Benny Wang
--
-- PROGRAMMER:	Benny Wang
--
-- INTERFACE:	const short LookupPortByService (const char * service, const char * protocol)
--					const char * service: The name of a service.
--					const char * protocol: The name of a protocol.
--
-- RETURNS:		The port number that service/protocol runs on if no error occured, nothing otherwise.
--
-- NOTES:
-- Takes the given service and protocol and looks up what port it is running on and returns it. The input is case
-- sensitive.
----------------------------------------------------------------------------------------------------------------------*/
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