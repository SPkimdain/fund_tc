//@checker SQL_INJECTION
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32

#include <Windows.h>
#include <sql.h>

#else

#define SQL_NTS -3

typedef void* SQLHSTMT;
extern int SQLExecDirect(SQLHSTMT handle, unsigned char*query, int length);

#endif /* _WIN32 */

void SQLI_001_funtion(SQLHSTMT sqlh){
  char* query = getenv("QUERY");

  SQLExecDirect(sqlh, (unsigned char*)query, SQL_NTS); //@violation SQL_INJECTION
}
