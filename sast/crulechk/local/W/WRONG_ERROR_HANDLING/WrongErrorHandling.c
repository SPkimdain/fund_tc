// @checker WRONG_ERROR_HANDLING

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

extern int fprintf ( FILE * stream, const char * format, ... );
extern void abort();

void WRNGERRHDNL_001_function(int param) {
  if (param == 0) {
	FILE* stderr;
    fprintf(stderr, "Something really bad happened!\n");
    abort();	//@violation WRONG_ERROR_HANDLING
  }
  exit(0);
}

void WRNGERRHDNL_001_function2(int param) {
	switch(param)
	{
	case 0:
		abort();	//@violation WRONG_ERROR_HANDLING
		break;
	default:
		break;
	}
}

 
void WRNGERRHDNL_001_function3(void) {
  WRNGERRHDNL_001_function(0);
  /* ... do the rest of f ... */
}
