// @checker READ_WRITE_BINARY_DATA

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

extern int fread ( void * ptr, int size, int count, FILE * stream );

struct myData {
  char c;
  long l;
};
 
/* ... */
void foo(){
	FILE *file;
	struct myData data;
	 
	/* Initialize file */
	 
	if (fread(&data, sizeof(struct myData), 1, file) < sizeof(struct myData)) {	//@violation READ_WRITE_BINARY_DATA
	  /* Handle error */
	}
}