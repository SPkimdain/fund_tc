// @checker USE_VALUE_FROM_FGETPOS
#define NULL 0
#define EINVAL 1
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

typedef int fpos_t;
typedef long size_t;
extern void * memset ( void * ptr, int value, size_t num );
extern int fsetpos ( FILE * stream, const fpos_t * pos );

enum { NO_FILE_POS_VALUES = 3 };
 
int opener(FILE* file) {
  int rc;
  fpos_t offset;
 
  /* ... */
 
  memset(&offset, 0, sizeof(offset));
 
  if (file == NULL) { return EINVAL; }
 
  /* Read in data from file */
 
  rc = fsetpos(file, &offset);	//@violation USE_VALUE_FROM_FGETPOS
  if (rc != 0 ) { return rc; }
 
  /* ... */
 
  return 0;
}