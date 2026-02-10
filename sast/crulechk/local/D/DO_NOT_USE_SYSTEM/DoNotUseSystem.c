// @checker DO_NOT_USE_SYSTEM
#define NULL 0
typedef long size_t;
extern int snprintf ( char * s, size_t n, const char * format, ... );
extern int system (const char* command);
extern void perror ( const char * str );

void foo()
{
	char *input = NULL;
 
	/* input gets initialized by user */
	 
	char cmdbuf[512];
	int len_wanted = snprintf(
	  cmdbuf, sizeof(cmdbuf), "any_cmd '%s'", input
	);
	if (len_wanted >= sizeof(cmdbuf)) {
	  perror("Input too long");
	}
	else if (len_wanted < 0) {
	  perror("Encoding error");
	}
	else if (system(cmdbuf) == -1) {	//@violation DO_NOT_USE_SYSTEM
	  perror("Error executing input");
	}
}
