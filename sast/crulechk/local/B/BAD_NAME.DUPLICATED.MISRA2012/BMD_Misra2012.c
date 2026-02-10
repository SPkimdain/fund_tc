//@checker BAD_NAME.DUPLICATED.MISRA2012
#define test int
#define test double 
#define Sum(x, y) ( ( x ) + ( y ) )	

int Sum;	//@violation BAD_NAME.DUPLICATED.MISRA2012

int BMD_Misra2012()
{
	int a;
	int test2 = a;
}

void test2() 
{
}