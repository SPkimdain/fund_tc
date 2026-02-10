//@checker POSTPONE_VARIABLE_DEFINITIONS

void PSTPVDEF_001_function1(int arg1, char arg2)
{
	switch( arg1 )
	{
	case 10:
		arg1++;
		break;
	}

	int x = 10;
	int y = 10; 
	if(arg2 == 10)
	{
		x = 5;
		arg1 = 5;
	}
	else if(arg2 == 5)
		y = 8;
	else
	{
		x = 8;
		if(arg1 == 10)
		{
			y = 5;
		}
	}
}

void PSTPVDEF_001_function2(int arg1, int arg2, int arg3)
{
	int x = 10; 
	int y = 10; 
	int zz, z = 10, zzz = 20; //@violation POSTPONE_VARIABLE_DEFINITIONS
	for(int i = 0; i < 10; i++)
	{
		if(arg1 == 10)
		{ 
			if(arg2 == 10)
			{ 				
				x++; 
				y++;
			}
			else
			{
				y++;
			}
		}
	}
	if(arg1 == 5)
	{ //@b-violation POSTPONE_VARIABLE_DEFINITIONS
		if(arg2 == 10)
		{
			if(arg3 == 10 && z == 5) //z »ç¿ë
			{
				int k = 0;
			}
			else
			{
				z++;
			}
		}
		else
		{
			z++;
		}
	}
}

void PSTPVDEF_001_function3(int arg1, int arg2, int arg3)
{
	int x = 10;
	int y = 20; //@violation POSTPONE_VARIABLE_DEFINITIONS
	int z = 50;
	switch( arg1 ) 
	{
	case 10:
		switch( arg3 )
		{
		case 30:
			x++;
			break;
		}		
		break;
	case 20:
		x--;
		break;
	case 30:
		if(arg2 == 10)
		{ //@b-violation POSTPONE_VARIABLE_DEFINITIONS
			y++; 
			z++; 
		}
		else
		{
			z++;
		}
	}
}

void PSTPVDEF_001_function4(int arg1, int arg2, int arg3)
{
	int x = 10; //@violation POSTPONE_VARIABLE_DEFINITIONS
	int y = 5;
	int z = 1; 
	if(arg1 == 10)
	{
		if(arg2 == 5)
		{
			if(arg3 == 1) 
				x++; //@b-violation POSTPONE_VARIABLE_DEFINITIONS
		}
	}

	while(arg1 < 10)
	{		
		y++;
		arg1++;

		if(arg2 == 10)
		{ 
			z++;
		}
	}
	
	int sum = 0; 
	for(int i = 0; i < 10; i++)
	{
		if( i % 2 == 0 )
		{ 
			sum += i;
		}
	}

	int sum2 = 0;
	for(int i = 0; i < 10; i++)
	{
		if( i % 2 == 0 )
		{ 
			sum2 += i;
		}
	}

	if(sum2 > 10)
	{
		return;
	}
}
