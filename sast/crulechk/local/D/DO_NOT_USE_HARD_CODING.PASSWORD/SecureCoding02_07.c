//@checker DO_NOT_USE_HARD_CODING.PASSWORD

typedef struct _iobuf
{
 char* _ptr;  
 int _cnt;    
 char* _base; 
 int _flag; 
 int _file; 
 int _charbuf; 
 int _bufsiz;  
 char* _tmpfname; 
} FILE;

typedef int SQLHENV;
typedef int SQLHDBC;
typedef char SQLCHAR;
typedef int SQLSMALLINT;

#define SQL_HANDLE_ENV 1
#define SQL_NULL_HANDLE 0
#define SQL_HANDLE_DBC 1

extern FILE *fopen(const char *filename, const char *mode);
extern int fclose(FILE *stream);
extern char * fgets ( char * str, int num, FILE * stream );
extern int strlen ( const char * str );
extern void SQLAllocHandle(int, int, SQLHENV *);
extern void SQLAllocHandle(int, SQLHENV, SQLHDBC*);
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
  SQLConnect(hdbc,	
                       (SQLCHAR*) server,
                       (SQLSMALLINT) strlen(server),
                       (SQLCHAR*) user,
                       (SQLSMALLINT) strlen(user),
                       /* Password is not encrypted.*/
                       "pwd",  	//@violation DO_NOT_USE_HARD_CODING.PASSWORD
                       (SQLSMALLINT) strlen(passwd) );
  return 0;
}
