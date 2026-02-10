// @checker DO_NOT_ASSUME_CONSTANT_WITH_EXPR

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

extern void setbuf ( FILE * stream, char * buffer );
extern int puts ( const char * str );
extern int fflush ( FILE * stream );

int foo(int bytes)
{
   FILE * stdout;
   int nblocks = 1 + ((bytes - 1) >> 9); //@violation DO_NOT_ASSUME_CONSTANT_WITH_EXPR
   char buf[nblocks];

   setbuf(stdout, buf);	
   puts("This is tutorialspoint");

   fflush(stdout);
   return(0);
}
