// @checker ONE_READ_CHAR_PUSH_BACK

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
extern int ungetc ( int character, FILE * stream );

void func()
{
	FILE *fp;
	FILE *fp1;
	char *file_name;
	 
	/* Initialize file_name */
	 
	fp = fopen(file_name, "rb");
	fp1 = fopen(file_name, "r");
	if (fp == 0) {
	  /* Handle error */
	}
	 
	/* Read data */

	
	
	if (ungetc('\n', fp) == 0) {
	  // Handle error 
	}

	if (ungetc('\r', fp) == 0) {	//@violation ONE_READ_CHAR_PUSH_BACK
	  // Handle error 
	}

	
	while(ungetc('\n', fp1) == 0)	//@violation ONE_READ_CHAR_PUSH_BACK
	{
		;
	}
	
}
