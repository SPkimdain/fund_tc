//@checker DO_NOT_USE_A_COPY_OF_A_FILE_OBJECT
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
extern int fputs ( const char * str, FILE * stream );

int main(void) {
    FILE my_stdout;
	FILE* stdout;
    FILE my_stdout2 = *(stdout);	//@violation DO_NOT_USE_A_COPY_OF_A_FILE_OBJECT
	FILE file_f;
	FILE file_g;
	FILE * hptr;
	FILE * iptr;


    my_stdout = *(stdout);	//@violation DO_NOT_USE_A_COPY_OF_A_FILE_OBJECT
    if (fputs("Hello, World!\n", &my_stdout) == EOF) {
	/* Handle error */
    }

	hptr = fopen(" afile.h" ," w" );

	iptr = hptr;        /* OK */
	file_f = *hptr;     //@violation DO_NOT_USE_A_COPY_OF_A_FILE_OBJECT
	file_g = file_f;    //@violation DO_NOT_USE_A_COPY_OF_A_FILE_OBJECT

    return 0;
}
