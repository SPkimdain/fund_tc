// @checker DO_NOT_USE_OCTAL

extern long int strtol (const char* str, char** endptr, int base);

int foo_func(int a, int b)
{
	return 123;
}

void func()
{
	char * test  = "10240";
	int a = strtol(test,0,10) * 1024;
	int tt = 0000;
	
	
	int k = 7777;
	int foo = k + 066;	//@violation	DO_NOT_USE_OCTAL
	char bar;
	foo = 00;	//@violation	DO_NOT_USE_OCTAL
	foo = 044;	//@violation	DO_NOT_USE_OCTAL
	bar = 75;
	foo = 222222;
	foo_func(011, //@violation	DO_NOT_USE_OCTAL
	044);	//@violation	DO_NOT_USE_OCTAL

}
