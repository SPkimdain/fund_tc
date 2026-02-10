// @checker STRICT_USE_FOPEN_MODE

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
extern int fputs ( const char * str, FILE * stream );
extern int fclose ( FILE * stream );

int foo(void) {
	FILE * pFile;
	pFile = fopen ("myfile.txt","abw");	//@violation STRICT_USE_FOPEN_MODE
	pFile = fopen ("myfile.txt","w");

	if (pFile!=0)
	{
	fputs ("fopen example",pFile);
	fclose (pFile);
	}
	return 0;
}