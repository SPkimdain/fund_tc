

/* SQLI_009 - sql injection with lambda. */

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

void SQLI_009_funtion(SQLHSTMT sqlh, char* name){
  auto&& SQLI_009_lambda = [](char* queryName) {
    char* query = getenv(queryName);

    return query;
  };


  char* q = SQLI_009_lambda(name);

  SQLExecDirect(sqlh, (unsigned char*)q, SQL_NTS); //@violation SQL_INJECTION
}
