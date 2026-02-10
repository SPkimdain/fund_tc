
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void MYSQL;

extern void mysql_query(MYSQL* handle, char* query);


/* SQLI_007 - function call. */
char* SQLI_007_get() {
  char* query = getenv("QUERY");
  return query;
}

void SQLI_007_funtion2(MYSQL* handle) {
  char* str = SQLI_007_get();
  char buf[512];

  strncpy(buf, str, 512); //propagate

  mysql_query(handle, buf); //@violation SQL_INJECTION
}
