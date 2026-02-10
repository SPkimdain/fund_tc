//@checker PREVENT_OPERATIONS_ON_DEVICES
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
extern int fclose ( FILE * stream );

void func1(char* fileName)
{
	FILE* file;
	/* 인자로 받은 파일명으로 파일을 여는 경우 */
	if ((file = fopen(fileName, "wb")) == 0) { //@violation PREVENT_OPERATIONS_ON_DEVICES
		/* Handle error */
	}

	/* Operate on the file */

	if (fclose(file) == EOF) {
		/* Handle error */
	}
}
