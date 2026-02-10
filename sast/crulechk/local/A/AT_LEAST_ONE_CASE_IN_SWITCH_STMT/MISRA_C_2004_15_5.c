// @checker AT_LEAST_ONE_CASE_IN_SWITCH_STMT

void normal_func(int foo)
{
	int bar = 0;
	
	switch(foo)
	{
	default:
		bar = 1;
		break;
	case 1:
		bar = 2;
		break;
	case 2:
		bar = 3;
		break;
	}
	
	switch(bar)
	{
	case 1:
		bar = 10;
		break;
	default:
		bar = 20;
		break;
	}

	switch(foo) // @violation	AT_LEAST_ONE_CASE_IN_SWITCH_STMT
	{	
		default:	
			bar = 1;
			break;
	}
	

	switch(foo)// @violation	AT_LEAST_ONE_CASE_IN_SWITCH_STMT
	{
	}
}
