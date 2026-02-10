// @checker DO_NOT_USE_BREAK_EXCEPT_SWITCH_STMT

void func(int foo)	
{
	switch(foo)
	{
	case 0:
		break;
	case 1:
		break;
	default:
		break;
	}
	
	for(int i =0; i < 100; i++)
	{
		if(i == 11){
			break;		//@violation DO_NOT_USE_BREAK_EXCEPT_SWITCH_STMT
		}
	}
}
