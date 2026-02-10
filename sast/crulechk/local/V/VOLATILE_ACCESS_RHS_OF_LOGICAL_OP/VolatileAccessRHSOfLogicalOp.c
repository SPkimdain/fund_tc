// @checker VOLATILE_ACCESS_RHS_OF_LOGICAL_OP

typedef unsigned int u_int32_t;

int test()
{
	return 10;
}

void func()
{
	u_int32_t i = 1u;
	u_int32_t bar = 10u;
	volatile u_int32_t foo = 11u;

	if( (bar == 100) && (100 == foo))	//@violation VOLATILE_ACCESS_RHS_OF_LOGICAL_OP
	{
		/*...*/
	}
	if((bar <= 100) || (foo == 1))	//@violation VOLATILE_ACCESS_RHS_OF_LOGICAL_OP
	{
		/*...*/
	}
	if( (bar > 100) && ( (foo + 1) != (foo - --i)))//@violation VOLATILE_ACCESS_RHS_OF_LOGICAL_OP
	{
		/*...*/
	}
	if( foo > i)
	{
		/*...*/
	}
	if( (foo == 1) && (bar == 100))
	{
		/* ... */
	}
}
