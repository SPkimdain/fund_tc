// @checker NO_CASE_IN_NESTED_BLOCK

void func1()
{
}

int main()
{
	int var = 1;
	switch(var) 
	{

		case 1: 
		case 5:
		{

			func1();

			case 2: // @violation NO_CASE_IN_NESTED_BLOCK
			func1();
			break;
			
			case 3: // @violation NO_CASE_IN_NESTED_BLOCK
			func1();
			break;

			default: // @violation NO_CASE_IN_NESTED_BLOCK
			func1();		
			break;
		}
	}
	
	switch(var) 
	{

		case 1: 
			func1();
		break;


		case 2:
		func1();
		break;
		
		case 3:
		func1();
		break;

		default:
		func1();		
		break;


		break;
	}

	return 1;
	
}