// @checker SET_ERRNO_ZERO_BEFORE_CALL_FUNC

extern unsigned long int strtoul (const char* str, char** endptr, int base);
extern int errno;
void foo()
{
	unsigned long number;
	char *c_str;
	char *endptr;
	int a;
	
	a = 0;
	/* ... */
	number = strtoul(c_str, &endptr, 0);		//@violation SET_ERRNO_ZERO_BEFORE_CALL_FUNC
	if (endptr == c_str || (number == 18446744073709551615 
							 && errno == 0)) {
	  /* Handle error */
	} else {
	  /* Computation succeeded */
	}
	errno = 0;
	number = strtoul(c_str, &endptr, 0);
}

void bar()
{
	char *c_str;
	char *endptr;
	errno = 0;
	unsigned long number;
	number = strtoul(c_str, &endptr, 0);	
}