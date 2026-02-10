
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef void MYSQL;

extern void mysql_query(MYSQL* handle, char* query);

/* SQLI_006 - mysql propagate. */

void SQLI_006_function(MYSQL* handle) {
  char* query = getenv("QUERY");

  char buf[512];

  strncpy(buf, query, 512); //propagate

  mysql_query(handle, buf); //@violation SQL_INJECTION
}


