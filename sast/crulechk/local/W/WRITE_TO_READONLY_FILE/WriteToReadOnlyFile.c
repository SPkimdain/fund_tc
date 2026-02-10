//@checker WRITE_TO_READONLY_FILE

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
extern int fprintf ( FILE * stream, const char * format, ... );

void fn ( void )
{
	FILE *fp2;
	fp2 = fopen ( "tmp2", "r" );
	FILE *fp = fopen ( "tmp", "r" );
	fprintf ( fp, "What happens now?" ); //@violation WRITE_TO_READONLY_FILE
	fprintf ( fp2, "What happens now?" ); //@violation WRITE_TO_READONLY_FILE
	fclose ( fp );
}