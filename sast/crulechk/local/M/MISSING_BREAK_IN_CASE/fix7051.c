//@checker MISSING_BREAK_IN_CASE

void test7051()
{
	int a= 5;
	int b= 10;
	
	switch(a)
	{
		case 1:
		break;
		
		case 5:
			if(b > 5)
			{
				break;
			}
			else
			{
				b--;
			}
		
		
						//@violation MISSING_BREAK_IN_CASE
		case 6:
			if(b > 5)
			{
				break;
			}
			else
			{
				break;
			}
		
		default:
		break;
	}
	
	
	
	
	
}