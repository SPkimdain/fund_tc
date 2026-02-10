// @checker USE_SHORT_FUNCTION

void USHRTFUNC_001_function1( int a, int b, int c, int d, int e)
{
	a = 10;
}

void USHRTFUNC_001_function2( int a, int b, int c, int d, int e, int f )
{
	a = 10;
}

void USHRTFUNC_001_function3( int a, int b, int c, int d, int e, int f, int g ) // @violation USE_SHORT_FUNCTION
{
	a = 10;
	b = 20;
}

void USHRTFUNC_001_function4( int a ) // @violation USE_SHORT_FUNCTION
{
	USHRTFUNC_001_function2(1,2,3,4,5,6);
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
	a = 10;
}
