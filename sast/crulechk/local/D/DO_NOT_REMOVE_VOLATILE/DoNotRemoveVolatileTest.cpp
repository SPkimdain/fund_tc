// @checker DO_NOT_REMOVE_VOLATILE

const unsigned int* foo( unsigned int *x);
volatile unsigned int* bar( unsigned int *x);

const unsigned int* foo( unsigned int *x)
{
	return x;
}

volatile unsigned int* bar( unsigned int *x)
{
	return (volatile unsigned int *)x;
}

int main()
{
	unsigned int x = 10;
	unsigned int *   pu32a = &x;
	const unsigned int * pu32_co= &x;
	volatile unsigned int * pu32_vo= &x; // @b-violation DO_NOT_REMOVE_VOLATILE
	volatile unsigned int * pu32_vo2= &x; // @b-violation DO_NOT_REMOVE_VOLATILE
	unsigned int * y= &x;
		
	pu32a = 3 + (unsigned int *) pu32_vo; // @violation DO_NOT_REMOVE_VOLATILE
	pu32a = (unsigned int *) ( 5 + (unsigned int *) pu32_vo2 ); // @violation DO_NOT_REMOVE_VOLATILE
	pu32a = (unsigned int *) ( 5 + (const unsigned int *) pu32_vo2 ); // @violation DO_NOT_REMOVE_VOLATILE
	pu32_vo = (volatile unsigned int *) pu32a;
	pu32a = (unsigned int *) bar( y ); //@violation DO_NOT_REMOVE_VOLATILE

	return 1;
}
