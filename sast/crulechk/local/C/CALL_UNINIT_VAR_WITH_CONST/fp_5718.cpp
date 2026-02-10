//@checker CALL_UNINIT_VAR_WITH_CONST
#include <string.h>

int foo(const int *);
int foo2(const int *);
int bar(int *);
int foobar(const int *, int *);


void test()
{
	
	int a = 50;
	int base[100];
	foobar(&a,base);
	bar(base);
	foo(base);
	
	
	int arr[100];

	memset(arr,100,1);
	foo(arr);
	
	int b[100];
	for(int index = 0 ; index < 100 ; index ++)
	{
		b[index] = 0;
	}
	foo2(b);
}


