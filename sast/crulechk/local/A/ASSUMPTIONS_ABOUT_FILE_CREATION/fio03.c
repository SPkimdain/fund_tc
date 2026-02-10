//@checker ASSUMPTIONS_ABOUT_FILE_CREATION 

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
extern int fclose(FILE *stream);

void func(char* fileName)
{
	FILE *fp;
	fp = fopen(fileName, "w"); //@violation ASSUMPTIONS_ABOUT_FILE_CREATION
	if(!fp)
	{
		/* Error. */
	}

	fclose(fp);

	/* x사용시 문제 없음. */
	fp = fopen(fileName, "wx");
	if(!fp)
	{
		/* Error. */
	}

	fclose(fp);

}


int main()
{
	return 0;
}


