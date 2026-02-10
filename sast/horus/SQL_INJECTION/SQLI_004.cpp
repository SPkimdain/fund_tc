
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32

#include <Windows.h>
#include <sql.h>

#else

#define SQL_NTS -3

typedef void* SQLHSTMT;
extern int SQLExecDirect(SQLHSTMT handle, unsigned char*query, int length);

#endif /* _WIN32 */

/* SQLI_004 - sanitize. */
extern char* makeSecureString(char* str);

void SQLI_004_funtion1(SQLHSTMT sqlh) {
  char* query = getenv("QUERY");
  char buf[512];
  char* ptr = 0;

  strcpy(buf, query); //propagate

  ptr = makeSecureString(buf);


  SQLExecDirect(sqlh, (unsigned char*)ptr, SQL_NTS); //It's ok.
}

void SQLI_004_funtion2(SQLHSTMT sqlh) {
  char* query = getenv("QUERY");
  char buf[512];
  char* ptr = 0;

  strcpy(buf, query); //propagate

  ptr = buf;

  SQLExecDirect(sqlh, (unsigned char*)ptr, SQL_NTS); //@violation SQL_INJECTION
}
