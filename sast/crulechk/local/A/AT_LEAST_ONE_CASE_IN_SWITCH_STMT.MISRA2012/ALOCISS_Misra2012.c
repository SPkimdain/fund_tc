// @checker AT_LEAST_ONE_CASE_IN_SWITCH_STMT.MISRA2012

void ALOCISS_Misra2012(int foo)
{
	int bar = 0;
	
	switch(foo)
	{
	case 3:
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

	switch(foo) // @violation	AT_LEAST_ONE_CASE_IN_SWITCH_STMT.MISRA2012
	{	
		default:	
			bar = 1;
			break;
	}
	

	switch(foo)// @violation	AT_LEAST_ONE_CASE_IN_SWITCH_STMT.MISRA2012
	{
	}
	
	switch(foo)
	{	
	case 1:
		bar = 10;
		break;
	case 2:
	case 3:
		break;
	}
	
	switch(foo) // @violation	AT_LEAST_ONE_CASE_IN_SWITCH_STMT.MISRA2012
	{	
	case 2:
	case 3:
		break;
	}



}
