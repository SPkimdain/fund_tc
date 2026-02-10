// @checker DO_NOT_CAST_FROM_INTEGRAL_TO_POINTER

signed int foo( unsigned int x );

signed int foo( unsigned int x )
{
	return ( signed int )x + 2;
}

int main()
{
	signed int *ps32a;
	unsigned int *pu32a;
	signed int s32a = 5;
	unsigned int u32a;
	signed int x = 10;
	unsigned int y = 10;
	signed int **pps32a;

	ps32a = &x;
	pu32a = &y;
	pps32a = &ps32a;
	
	(ps32a) = 5 + ((signed int *) s32a); // @violation DO_NOT_CAST_FROM_INTEGRAL_TO_POINTER
	
	ps32a = (signed int *) &s32a;
	*pps32a = (signed int *) x; // @violation DO_NOT_CAST_FROM_INTEGRAL_TO_POINTER

	ps32a = (signed int *)foo(x); //@violation DO_NOT_CAST_FROM_INTEGRAL_TO_POINTER

	return 1;
}
