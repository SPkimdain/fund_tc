//@checker TMP_FILE_IN_SHARED_DIR
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
extern char * tmpnam ( char * str );

void TMPFISD_001_function(){
  char file_name[256] = { 0, };
  int fd = 0;
  if(!(tmpnam(file_name))) { //@violation TMP_FILE_IN_SHARED_DIR
    return;
  }
  //  TMP FILE IN SHARED DIR
  FILE *fp = fopen(file_name, "wb+"); 
  /* writing tmp file codes here */
}
