// windows 용 코드.

#ifdef _WIN32

#include <process.h>

#define EXECL _execl

#else 

#include <unistd.h>

#define EXECL execl

#endif

#include <stdlib.h>

extern char *LOGIN_PROGRAM;
extern char *slavename, *host, *pam_svc_name;
extern char *AuthenticatingUser;

void ERD_001_function(const char* name) {
	(void)EXECL(LOGIN_PROGRAM, "login", //@violation EXECL_REVEALS_DATA
  "-p",
  "-d", slavename,
  "-h", host,
  "-s", pam_svc_name,
  (AuthenticatingUser != NULL ? AuthenticatingUser :
  name),
  0);
}
