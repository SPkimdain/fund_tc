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
extern void SQLFreeHandle(int, SQLHDBC);
extern void SQLConnect(SQLHDBC, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT, SQLCHAR*, SQLSMALLINT);
extern char *salt;
extern char *crypt(char *, char *);

int UOHCK_001_function(char *user, char *passwd){
  char *server = "DBserver";
  char *cpasswd;
  SQLHENV henv;
  SQLHDBC hdbc;
  SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
  SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
  cpasswd = crypt(passwd, salt);
  /* Hardcoded cryptographic key is in the code..*/
  if (strcmp(cpasswd, "68af404b513073582b6c63e6b") != 0) { //@violation USE_OF_HARDCODED_CRYPTOGRAPHIC_KEY
    SQLFreeHandle(SQL_HANDLE_ENV, henv);
    SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
    printf("Incorrect password\n");
    return -1;
  }
  
  SQLFreeHandle(SQL_HANDLE_ENV, henv);
  SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  return 0;
}
