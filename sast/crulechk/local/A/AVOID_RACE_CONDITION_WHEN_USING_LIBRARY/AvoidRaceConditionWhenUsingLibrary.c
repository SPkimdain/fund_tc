//@checker AVOID_RACE_CONDITION_WHEN_USING_LIBRARY

extern int printf ( const char * format, ... );
extern int rand ();
extern int errno;
extern char * strerror ( int errnum );
extern char * strtok ( char * str, const char * delimiters );

extern void c16rtomb(char* a, char b, int* c)
{
}

  
int ARCWUL_001_function() {
	int requiredSize;
	errno = 0;
	char *temp;
	char in = 'a';
	char out[100];
	int rc, i, st = 0;
	
	printf("%d\n", rand()); //@violation AVOID_RACE_CONDITION_WHEN_USING_LIBRARY
	
	char *errmsg = strerror(errno); //@violation AVOID_RACE_CONDITION_WHEN_USING_LIBRARY

	temp = strtok(errmsg, " "); //@violation AVOID_RACE_CONDITION_WHEN_USING_LIBRARY	
	
	c16rtomb(out, in, &st); //@violation AVOID_RACE_CONDITION_WHEN_USING_LIBRARY
	
	return 0;
}
