
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

/* SQLI_002 - propagate. */

void SQLI_002_funtion(SQLHSTMT sqlh){
  char* query = getenv("QUERY");
  char buf[512];
  
  strcpy(buf, query); //propagate

  SQLExecDirect(sqlh, (unsigned char*)buf, SQL_NTS); //@violation SQL_INJECTION
}
