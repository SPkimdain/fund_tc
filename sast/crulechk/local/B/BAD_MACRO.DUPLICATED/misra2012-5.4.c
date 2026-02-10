//@checker BAD_MACRO.DUPLICATED
#define test_macro_name_test_macro_name_test_macro_name_test_macro_name_test_macro_name char	
#define test int


#define while( E ) for ( ;  ( E ) ; ) 
#define unless( E ) if ( ! ( E ) )
#define test double //@violation BAD_MACRO.DUPLICATED
#define Sum(x, y) ( ( x ) + ( y ) )

int Sum;

int avkamn()
{
	int a;
	int test2 = a;
	
	
	
}

void test2() 
{
}