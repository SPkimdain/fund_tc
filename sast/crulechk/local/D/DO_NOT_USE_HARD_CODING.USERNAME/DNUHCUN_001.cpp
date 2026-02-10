//@checker DO_NOT_USE_HARD_CODING.USERNAME

#define SQL_NULL_HANDLE 0
#define SQL_HANDLE_ENV 1
#define SQL_HANDLE_DBC 2

typedef long size_t;
typedef void* SQLHENV;
typedef void* SQLHDBC;
typedef char SQLCHAR;
typedef int SQLSMALLINT;

extern size_t strlen ( const char * str );
extern void SQLAllocHandle(int flag, void* handle, void* henv);
extern void SQLConnect(void* hdbc, SQLCHAR* server, int len, char* userName, int userSize, char* pwd, int pwdSize);

int DNUHCUN_001_function(char *server, char *passwd){
  SQLHENV henv;
  SQLHDBC hdbc;
  SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
  SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
  SQLConnect(hdbc, 
    (SQLCHAR*) server, 
    (SQLSMALLINT)strlen(server),
    "root", //@violation DO_NOT_USE_HARD_CODING.USERNAME
    4,
    passwd,
    strlen(passwd));
  return 0;
}

