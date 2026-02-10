//@checker BAD_CALL.NUMBER_OF_VARARGS_MISMATCH
extern int printf ( const char * format, ... );

int BadCallNumberOfVarArgsMismatch()
{
	int x = 0;
	char * str = 0 ;
	printf("noncompliant %[^'\n'], %[^','], %d, %[^'\n']", str,str,x,str);	
	printf("noncompliant %d and %s %f ", x);	//@violation BAD_CALL.NUMBER_OF_VARARGS_MISMATCH
	printf("this is test %d", x);
  
  printf("compliant asterisk %*d", 5, 10); //It's ok.
  printf("noncompliant asterisk %*d", 10); //@violation BAD_CALL.NUMBER_OF_VARARGS_MISMATCH
  
	return 0;
}
