// @checker NO_MORE_THAN_ONE_BREAK

int main()
{
	int i, j;
	int sum = 0;

	for(i = 0; i < 10; i++)  // @violation NO_MORE_THAN_ONE_BREAK         
	{

		if(sum > 20) 
		{
			break; // @b-violation NO_MORE_THAN_ONE_BREAK         
		}

		if(sum == 10) 
		{
			break; // @b-violation NO_MORE_THAN_ONE_BREAK         
		}
	sum += i;
	}
	
	sum = 0;
	
	for(i = 0; i < 10; i++)
	{

		if(sum > 20) 
		{
		break;
		}
	sum += i;
	}
	
	sum = 0;
	
	while( i < 20 ) // @violation NO_MORE_THAN_ONE_BREAK        
	{

		for(j = 0; j < 10; j++) // @violation NO_MORE_THAN_ONE_BREAK
		{

			if(j * j > 20) 
			{
				break; // @b-violation NO_MORE_THAN_ONE_BREAK
			}
			if(j * j == 20) 
			{
				break; // @b-violation NO_MORE_THAN_ONE_BREAK
			}
		}
		
		
		if(sum > 20) 
		{
			break;	// @b-violation NO_MORE_THAN_ONE_BREAK
		}
		if(sum == 20) 
		{
			break;	// @b-violation NO_MORE_THAN_ONE_BREAK
		}
		
	sum += i;
	}
	
	sum = 0;
	
	for(i = 0; i < 10; i++)
	{

		for(j = 0; j < 10; j++) // @violation NO_MORE_THAN_ONE_BREAK
		{

			if(j * j > 20) 
			{
				break; // @b-violation NO_MORE_THAN_ONE_BREAK
			}
			if(j * j == 20) 
			{
				break; // @b-violation NO_MORE_THAN_ONE_BREAK
			}
		}

	sum += i;
	}
}

	