// @checker UNREACHABLE_CASE

int f(int a)
{
	return a+1;
}

int foo(unsigned int p1){
	int k = 10;
	int y = 10;
	switch(p1)
	{
	case 1:
		k = 10;
		break;
	case 2:
		k = 20;
		break;
	case -1:	//@violation	UNREACHABLE_CASE
		k = -1;
		break;
	default:
		k = 11;
		break;
	}

	switch(k)
	{
	case 2:
		y = 11;
		break;
	case 3:
		y = 12;
		break;
	default:
		y = 13;
		break;
	}
	return 1;
}
