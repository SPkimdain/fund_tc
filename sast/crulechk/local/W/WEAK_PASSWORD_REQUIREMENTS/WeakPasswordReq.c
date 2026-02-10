//@checker WEAK_PASSWORD_REQUIREMENTS

#include "WeakPasswordReq.h"
#define NULL 0

int authentication(char* id, char* pwd)
{
	MYSQL *connectInstance;
	connectInstance = mysql_init(NULL);
	mysql_real_connect(connectInstance, "192.168.100.211", id, pwd, "database", 0, NULL, 0); //@violation  WEAK_PASSWORD_REQUIREMENTS
	
	/* ... */
	
	return 0;
}


