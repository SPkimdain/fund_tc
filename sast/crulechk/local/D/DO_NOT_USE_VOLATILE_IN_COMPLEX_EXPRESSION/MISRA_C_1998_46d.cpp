//@checker DO_NOT_USE_VOLATILE_IN_COMPLEX_EXPRESSION 

int main()
{
	int x = 10;
	int y = 5;
	volatile int v = 20;

	x = v * v; //@violation DO_NOT_USE_VOLATILE_IN_COMPLEX_EXPRESSION

	if( v * v ) //@violation DO_NOT_USE_VOLATILE_IN_COMPLEX_EXPRESSION
	{
		y++;
	}

	int z = 5;
	y = ( v + z ) / ( v - x ); //@violation DO_NOT_USE_VOLATILE_IN_COMPLEX_EXPRESSION

	int k = v * v; //@violation DO_NOT_USE_VOLATILE_IN_COMPLEX_EXPRESSION

	x = v + z;

}
