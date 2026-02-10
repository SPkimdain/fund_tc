// @checker MULTIPLE_FILE_ATTRIBUTES
#define NULL 0

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

int foo(int bytes)
{
	char *file_name;
 
	/* Initialize file_name */
	 
	FILE *fd = fopen(file_name, "w");
	if (fd == NULL) {
	  /* Handle error */
	}
	 
	/*... write to file ...*/
	 
	fclose(fd);
	fd = NULL;
	 
	/*
	 * A race condition here allows for an attacker to switch 
	 * out the file for another 
	 */
	 
	/* ... */
	 
	fd = fopen(file_name, "r");	//@violation MULTIPLE_FILE_ATTRIBUTES
	if (fd == NULL) {
	  /* Handle error */
	}
	 
	/*... read from file ...*/
	 
	fclose(fd);
	fd = NULL;
  
  return 0;
}

int bar()
{
	char *file_name;
	FILE *fd;
	 
	/* Initialize file_name */
	 
	fd = fopen(file_name, "r+");	//@violation MULTIPLE_FILE_ATTRIBUTES
	if (fd == NULL) {
	  /* Handle error */
	}
	 
	/* Read user's file */
	 
	fclose(fd);
	fd = NULL; 

  return 0;
}