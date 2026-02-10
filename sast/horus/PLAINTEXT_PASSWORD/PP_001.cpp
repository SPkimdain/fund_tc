#include <stdio.h>
#include <string.h>

typedef int SQLHENV;
typedef int SQLHDBC;
typedef char SQLCHAR;
typedef int SQLSMALLINT;

#define SQL_HANDLE_ENV 1
#define SQL_NULL_HANDLE 0
#define SQL_HANDLE_DBC 1

extern void SQLAllocHandle(int, int, SQLHENV *);
extern void SQLAllocHandle(int, SQLHENV, SQLHDBC*);
extern void SQLFreeHandle(int type, int handle);
extern void SQLConnect(SQLHDBC, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT);

int PP_001_function(){
  FILE *fp; char *server = "DBserver";
  char passwd[20];
  char user[20];
  SQLHENV henv;
  SQLHDBC hdbc;
  fp = fopen("config", "r");
  fgets(user, sizeof(user), fp);
  fgets(passwd, sizeof(passwd), fp);
  fclose(fp);
  SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
  SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
  SQLConnect(hdbc,	//@violation PLAINTEXT_PASSWORD
                       (SQLCHAR*) server,
                       (SQLSMALLINT) strlen(server),
                       (SQLCHAR*) user,
                       (SQLSMALLINT) strlen(user),
                       /* passwd is not encrypted.*/
                       (SQLCHAR*)passwd,  
                       (SQLSMALLINT) strlen(passwd) );

  SQLFreeHandle(SQL_HANDLE_ENV, henv);
  SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  return 0;
}
