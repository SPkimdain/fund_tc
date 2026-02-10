//@checker HEAP_INSPECTION
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOGON32_LOGON_NETWORK 0
#define LOGON32_PROVIDER_DEFAULT 1

typedef void* HANDLE;

extern int LogonUserA(char* name, char* domain, char* pwd, int flag1, int flag2, HANDLE* handle);
extern void CloseHandle(HANDLE handle);
extern void printLine(const char* str);

void HEAPISP_001_function(char* username, char* domain) {
  HANDLE hUser;
  
  char * password = (char *)malloc(100*sizeof(char));
  /* ... */

  if (LogonUserA(
      username,
      domain,
      password,
      LOGON32_LOGON_NETWORK,
      LOGON32_PROVIDER_DEFAULT,
      &hUser) != 0) {
        
      printLine("User logged in successfully.");
      CloseHandle(hUser);
  }
  else {
      printLine("Unable to login.");
  }

  free(password); 

  return;
} //@violation HEAP_INSPECTION
