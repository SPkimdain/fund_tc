// @checker DO_NOT_USE_SAME_NAME_IN_NESTED

extern int printf ( const char * format, ... );

int variable; // @b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
int variable2; // @b-violation DO_NOT_USE_SAME_NAME_IN_NESTED

void func (void) 
{

	int variable;  // @violation DO_NOT_USE_SAME_NAME_IN_NESTED
	variable = 10;
	
	printf("variable:%d\n",variable);
}

void func2( int variable ) // @violation DO_NOT_USE_SAME_NAME_IN_NESTED
{
	variable = 1;
	printf("variable:%d\n",variable);
}

void func3() // @b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
{
	int x = 5; // @b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
	int y = 10; // @b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
	printf("x:%d\n",x);
	{
		int x; // @violation DO_NOT_USE_SAME_NAME_IN_NESTED
		x = 1;
		printf("x:%d\n",x);
	}
	
	for(int x = 0; x < 5; x++) // @violation DO_NOT_USE_SAME_NAME_IN_NESTED
	{
		printf("x:%d\n",x);
	}
	
	while( y == 0 )
	{
		int y = 5; // @violation DO_NOT_USE_SAME_NAME_IN_NESTED
		int z = 3; // @b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
		if( z == 3 )
		{
			int z = 1; // @violation DO_NOT_USE_SAME_NAME_IN_NESTED
		}
	}
	
	switch( x )
	{
	default:
		int x = 10; // @violation DO_NOT_USE_SAME_NAME_IN_NESTED
		break;
	}
}

void func4() // @b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
{
	int func3 = 10; //@violation DO_NOT_USE_SAME_NAME_IN_NESTED
func4: //@violation DO_NOT_USE_SAME_NAME_IN_NESTED
	int x = 5;
}

int main()
{
	int variable = 1; // @violation DO_NOT_USE_SAME_NAME_IN_NESTED
	int variable2; // @violation DO_NOT_USE_SAME_NAME_IN_NESTED
	
	variable2 = 5;

	func();
	func2(2);
	func3();
}
