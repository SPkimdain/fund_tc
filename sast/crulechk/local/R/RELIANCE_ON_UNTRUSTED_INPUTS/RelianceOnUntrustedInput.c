//@checker RELIANCE_ON_UNTRUSTED_INPUTS
#include <string.h>

/* Cgic Library : http://www.boutell.com/cgic/ */
extern int cgiFormString(char *name, char *result, int max);

int untrustedInputsTest(char* verification)
{
	int cgiTrust = 0;
	char value[1024];
	
	cgiFormString("value", value, sizeof(value));
	if(strlen(value) != 0 && strcmp(value, verification) == 0) //@violation  RELIANCE_ON_UNTRUSTED_INPUTS
	{
		cgiTrust = 1;
		return cgiTrust;
	}
	else
	{
		cgiTrust = 0;
		return cgiTrust;
	}
}
