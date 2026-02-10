/* PP_002 - sanitize */

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
extern char *verify(char *);

int PP_002_function(){
  FILE *fp; char *server = "DBserver";
  char passwd[20];
  char user[20];
  char *verifiedPwd;
  SQLHENV henv;
  SQLHDBC hdbc;
  fp = fopen("config", "r");
  fgets(user, sizeof(user), fp);
  fgets(passwd, sizeof(passwd), fp);
  fclose(fp);
  
  verifiedPwd = verify(passwd);
  
  SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
  SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
  SQLConnect(hdbc,
    (SQLCHAR*)server,
    (SQLSMALLINT)strlen(server),
    (SQLCHAR*)user,
    (SQLSMALLINT)strlen(user),
    /* Password is not encrypted.*/
    (SQLCHAR*)verifiedPwd, //It's ok.
    (SQLSMALLINT)strlen(verifiedPwd));

  SQLFreeHandle(SQL_HANDLE_ENV, henv);
  SQLFreeHandle(SQL_HANDLE_DBC, hdbc);

  return 0;
}



int PP_002_function2(){
  FILE *fp; char *server = "DBserver";
  char passwd[20];
  char user[20];
  char buf[20];

  SQLHENV henv;
  SQLHDBC hdbc;
  fp = fopen("config", "r");
  fgets(user, sizeof(user), fp);
  fgets(passwd, sizeof(passwd), fp);
  fclose(fp);
  
  strcpy(buf, passwd); //propagation

  SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
  SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
  SQLConnect(hdbc, (SQLCHAR*) server, (SQLSMALLINT) strlen(server), //@violation PLAINTEXT_PASSWORD 
    (SQLCHAR*) user, (SQLSMALLINT) strlen(user),
    /* Password is not encrypted.*/
    (SQLCHAR*)buf, 
    (SQLSMALLINT)strlen(buf));

  SQLFreeHandle(SQL_HANDLE_ENV, henv);
  SQLFreeHandle(SQL_HANDLE_DBC, hdbc);

  return 0;
}
