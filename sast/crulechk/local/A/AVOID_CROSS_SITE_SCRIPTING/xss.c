//@checker AVOID_CROSS_SITE_SCRIPTING

/* Cgic Library : http://www.boutell.com/cgic/ */
extern int cgiFormString(char *name, char *result, int max);
extern void cgiHeaderCookieSetString(char *name, char *value, int secondsToLive, char *path, char *domain);
extern int strlen(const char *str);

int main()
{
	char cookieName[1024];
	char data[1024];
	char* dataStr = "DataName";
	char* cgiScriptName = "ScriptName";
	char* cgiServerName = "www.fasoo.com";

	cgiFormString("cookieName", cookieName, sizeof(cookieName));  //@violation  AVOID_CROSS_SITE_SCRIPTING  
	cgiFormString(dataStr, data, sizeof(data));  //@violation  AVOID_CROSS_SITE_SCRIPTING  
	if (strlen(cookieName) != 0)
	{
	 cgiHeaderCookieSetString(cookieName, data, 86400, cgiScriptName, cgiServerName);
	 /* ... */
	}
}

