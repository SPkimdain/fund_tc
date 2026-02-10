// @checker NOT_LAST_DEFAULT_CASE

void normal_func(int foo)
{
	int bar = 0;
	switch(foo)	
	{
	case 1:
		bar = 20;
		break;
	case 2:
		bar = 10;
		break;
	}

	switch(foo) {	
		default:	// @violation	NOT_LAST_DEFAULT_CASE
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
