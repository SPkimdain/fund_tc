//@checker RESET_STRING_ON_FGETS_FAILURE 
#define BUFFER_SIZE 1024
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

extern char * fgets ( char * str, int num, FILE * stream );


void func(FILE *file, int x) {
  char buf[BUFFER_SIZE];
 
  if (fgets(buf, sizeof(buf), file) == NULL) { //@violation RESET_STRING_ON_FGETS_FAILURE
    /* Set error flag and continue */
  }

  if (fgets(buf, sizeof(buf), file) != NULL) { //@violation RESET_STRING_ON_FGETS_FAILURE
    /* Set error flag and continue */
	*buf = '\0';
  }
  else
  {
  }

  if (x == 10 && fgets(buf, sizeof(buf), file) == NULL) { //@violation RESET_STRING_ON_FGETS_FAILURE
    /* Set error flag and continue */
  }

  if (x == 10 && fgets(buf, sizeof(buf), file) == NULL) {
    /* Set error flag and continue */
	  if( x > 15 )
	  {
		  *buf = '\0';
	  }
  }

    if( x > 15 )
  {
	if (x == 10 && fgets(buf, sizeof(buf), file) == NULL) { //@violation RESET_STRING_ON_FGETS_FAILURE
	}
  }

  if( x > 15 )
  {
	if (x == 10 && fgets(buf, sizeof(buf), file) == NULL) { //@violation RESET_STRING_ON_FGETS_FAILURE
		if (fgets(buf, sizeof(buf), file) == NULL) {
		}
	}
  }

  
  if( x > 15 )
  {
	if (x == 10 && fgets(buf, sizeof(buf), file) == NULL) {
		if (fgets(buf, sizeof(buf), file) == NULL) {
			*buf = '\0';
		}
	}
  }
}

void func2(FILE *file) {
  char buf[BUFFER_SIZE];
 
  if (fgets(buf, sizeof(buf), file) == NULL) {
    /* Set error flag and continue */
    *buf = '\0';
  }

  if (fgets(buf, sizeof(buf), file) != NULL) {
    /* Set error flag and continue */
  }
  else
  {
	*buf = '\0';
  }


}

int main()
{
	return 1;
}
