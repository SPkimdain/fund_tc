//@checker AVOID_SIDE_EFFECT_IN_PARAMETERS
#define EOF 0
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
extern int getc ( FILE * stream );
extern int ferror ( FILE * stream );
extern int feof ( FILE * stream );
extern int fclose ( FILE * stream );

int FIO41_C_function(const char* fileName) {
  FILE* fptr = 0;
  FILE* stdin;
  int c = getc(fptr = fopen(fileName, "r"));  //@violation AVOID_SIDE_EFFECT_IN_PARAMETERS
  if(feof(stdin) || ferror(stdin)) {
    return -1;
  }


  if(fclose(fptr) == EOF) {
    return -1;
  }

  return 0;
}
