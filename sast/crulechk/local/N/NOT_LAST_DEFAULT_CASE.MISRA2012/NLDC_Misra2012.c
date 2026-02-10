// @checker NOT_LAST_DEFAULT_CASE.MISRA2012
void NLDC_Misra2012(int foo)
{
	int bar = 0;
	
	switch(foo)	
	{
	default:	
			bar = 1;
			break;
	case 2:
		bar = 10;
		break;
	}
	
	switch(foo)	
	{
	case 1:
		bar = 20;
		break;
	default:	// @violation	NOT_LAST_DEFAULT_CASE.MISRA2012
			bar = 1;
			break;
	case 2:
		bar = 10;
		break;
	}

	switch(foo) {	
		default:	
			bar = 1;
			break;
		case 0:
			bar = 2;
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

}
