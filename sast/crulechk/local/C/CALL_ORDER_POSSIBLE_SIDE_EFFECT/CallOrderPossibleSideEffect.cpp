// @checker CALL_ORDER_POSSIBLE_SIDE_EFFECT

typedef unsigned int u_int32_t;

int test(int *t)
{
	return 10;
}

int test1(int &t1)
{
	return 111;
}

void func()
{
	int i = 1;
	int bar = 10;
	volatile u_int32_t foo = 11;
	int *foo1 = &bar;

	if( (bar > 100) || (test1(bar)))	//@violation CALL_ORDER_POSSIBLE_SIDE_EFFECT
	{
		/* ... */
	}

	if( (bar == 100) && (test(foo1)))	//@violation CALL_ORDER_POSSIBLE_SIDE_EFFECT
	{
		/*...*/
	}
	if( (foo == 1) && (test(&bar))) //@violation CALL_ORDER_POSSIBLE_SIDE_EFFECT
	{
		/* ... */
	}

	if( test(foo1)){
	/*..... */
	}

	if( test1(bar) && ( i < 100))
	{
		/* .... */
	}
}
