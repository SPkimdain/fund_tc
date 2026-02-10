// @checker STRING_LITERAL_MODIFICATION
extern void* malloc (int size);

void foo()
{
	char *p  = "string literal";	
	char a[] = "string literal";
	char *p1;
	p[0] = 'S';	//@violation	STRING_LITERAL_MODIFICATION
	a[0] = 'S';

	p1 = (char*)malloc(100);
	p1[0] = 'a';

}

