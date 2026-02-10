// @checker MULTIPLE_ENV_WITH_SAME_NAME

#define NULL 0

extern char* getenv (const char* name);
extern int printf ( const char * format, ... );
extern int putenv(const char*);

void foo()
{

	if (putenv("TEST_ENV=foo") != 0) {	
	  /* Handle error */
	}
	if (putenv("Test_ENV=bar") != 0) {	//@violation MULTIPLE_ENV_WITH_SAME_NAME
	  /* Handle error */
	}

	if (putenv("env_var=bar") != 0) {
	  /* Handle error */
	}

	if (putenv("test_env=bar") != 0) {	//@violation MULTIPLE_ENV_WITH_SAME_NAME
	  /* Handle error */
	}
	 
	const char *temp = getenv("TEST_ENV");
	 
	if (temp == NULL) {
	  /* Handle error */
	}
	 
	printf("%s\n", temp);
}