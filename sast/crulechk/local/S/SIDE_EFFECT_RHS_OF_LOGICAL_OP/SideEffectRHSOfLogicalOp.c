// @checker SIDE_EFFECT_RHS_OF_LOGICAL_OP

int test()
{
	return 10;
}

void func()
{
	int i = 1;
	int bar = 10;
	if( (bar == 100) && (100 == ++i))	//@violation SIDE_EFFECT_RHS_OF_LOGICAL_OP
	{
		/*...*/
	}
	if((bar <= 100) || (i++ == 1))	//@violation SIDE_EFFECT_RHS_OF_LOGICAL_OP
	{
		/*...*/
	}
	if( (bar > 100) && ( (bar + 1) != (bar - --i)))//@violation SIDE_EFFECT_RHS_OF_LOGICAL_OP
	{
		/*...*/
	}
	if( bar > i)
	{
		/*...*/
	}
}
