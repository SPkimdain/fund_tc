
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

/* SQLI_003 - function call. */
char* SQLI_003_get() {
  char* query = getenv("QUERY");
  return query;
}

void SQLI_003_funtion2(SQLHSTMT sqlh) {
  char* str = SQLI_003_get();
  char buf[512];

  strcpy(buf, str); //propagate

  SQLExecDirect(sqlh, (unsigned char*)buf, SQL_NTS); //@violation SQL_INJECTION
}
