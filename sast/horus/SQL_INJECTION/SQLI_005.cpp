
#include <stdio.h>
#include <stdlib.h>


typedef void MYSQL;

extern void mysql_query(MYSQL* handle, char* query);

/* SQLI_005 - mysql. */

void SQLI_005_function(MYSQL* handle) {
  char* query = getenv("QUERY");

  mysql_query(handle, query); //@violation SQL_INJECTION
}


