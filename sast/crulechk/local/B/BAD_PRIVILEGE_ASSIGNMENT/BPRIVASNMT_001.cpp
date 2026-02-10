//@checker BAD_PRIVILEGE_ASSIGNMENT
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

extern FILE * fopen ( const char * filename, const char * mode );
extern int fclose ( FILE * stream );
extern char * fgets ( char * str, int num, FILE * stream );
extern int seteuid(int id);
extern int getuid();

char* BPRIVASNMT_001_function() {
  char buf[100];
  
  FILE *fp;
  seteuid(0); //@violation BAD_PRIVILEGE_ASSIGNMENT
  fp = fopen("/etc/passwd", "r");
  fgets(buf, sizeof(buf), fp);
  seteuid(getuid());  
  fclose(fp);
  
  return 0;
}
