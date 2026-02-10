// @checker DO_NOT_USE_ABORT_STREAM_OPENED

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

extern FILE *fopen(const char *filename, const char *mode);
extern int fprintf ( FILE * stream, const char * format, ... );
extern void abort ();


int write_data(void) {
  const char *filename = "hello.txt";
  FILE *f = fopen(filename, "w");
  if (f == 0) {
    /* Handle error */
  }
  fprintf(f, "Hello, World\n");
  /* ... */
  abort(); //@violation DO_NOT_USE_ABORT_STREAM_OPENED
  /* ... */
  return 0;
}
 
int main(void) {
  write_data();
  return 0;
}