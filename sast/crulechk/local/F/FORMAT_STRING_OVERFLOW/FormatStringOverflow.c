//@checker FORMAT_STRING_OVERFLOW
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

extern int sprintf ( char * str, const char * format, ... );
extern int fscanf ( FILE * stream, const char * format, ... );

enum { BUF_LENGTH = 1024 };
 
void get_data(const char *msg ) {	//@b-violation FORMAT_STRING_OVERFLOW
  char buf[BUF_LENGTH];	//@b-violation FORMAT_STRING_OVERFLOW
  char filename[128];
  sprintf(filename, "%s.txt", msg);	//@violation FORMAT_STRING_OVERFLOW
  sprintf(filename, "%123s.txt", msg);
  fscanf(stdin, "%2000s %d", buf, 123);	//@violation FORMAT_STRING_OVERFLOW
  fscanf(stdin, "%s %d", msg, 123);	//@violation FORMAT_STRING_OVERFLOW
  fscanf(stdin, "%123s", buf);
  fscanf(stdin, "%s", buf);	//@violation FORMAT_STRING_OVERFLOW
  
}
