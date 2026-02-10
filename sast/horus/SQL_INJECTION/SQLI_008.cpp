
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef void MYSQL;

extern void mysql_query(MYSQL* handle, char* query);
extern char* makeSecureString(char* str);

/* SQLI_008 - mysql sanitize. */


void SQLI_008_function(MYSQL* handle) {
  char* query = getenv("QUERY");

  char buf[512];
  char* ptr = 0;

  strncpy(buf, query, 512); //propagate

  makeSecureString(buf);

  mysql_query(handle, buf); //It's ok.
}



void SQLI_008_function2(MYSQL* handle) {
  char* query = getenv("QUERY");

  char buf[512];

  strncpy(buf, query, 512); //propagate

  mysql_query(handle, buf); //@violation SQL_INJECTION
}
