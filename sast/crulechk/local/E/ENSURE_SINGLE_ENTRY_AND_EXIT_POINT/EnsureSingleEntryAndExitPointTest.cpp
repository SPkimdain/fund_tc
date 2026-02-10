//@checker ENSURE_SINGLE_ENTRY_AND_EXIT_POINT

int main()
{
	for( int i = 0; i < 2; i++ )
	{
		int x = 10;
		while( x != 0 )
		{
			x--;
		}
	}
	
	for( int i = 0; i < 10; i++ ) 
	{ //@violation ENSURE_SINGLE_ENTRY_AND_EXIT_POINT
		if( i == 5 )
		{
			break; //@b-violation ENSURE_SINGLE_ENTRY_AND_EXIT_POINT
		}
	}

	for( int i = 0; i < 10; i++ )
	{
		for( int j = 0; j < 20; j++ )  
		{ //@violation ENSURE_SINGLE_ENTRY_AND_EXIT_POINT
			if( j == 10 )
			{
				break; //@b-violation ENSURE_SINGLE_ENTRY_AND_EXIT_POINT
			}
		}
	}

	int i = 0;
	while( i < 10 )  
	{ //@violation ENSURE_SINGLE_ENTRY_AND_EXIT_POINT
		i++;
		if( i == 5 )
		{
			break; //@b-violation ENSURE_SINGLE_ENTRY_AND_EXIT_POINT
		}
		else if( i == 8 )
		{
			break;
		}
	}

	i = 0;

	do 
	{ //@violation ENSURE_SINGLE_ENTRY_AND_EXIT_POINT
		i++;
		if( i == 3 )
		{
			break; //@b-violation ENSURE_SINGLE_ENTRY_AND_EXIT_POINT
		}
	} while( i < 10 );

	for( int j = 0; j < 10; j++ )
	{
		int x = 10;
		switch( x )
		{
		case 10:
			break;
		default:
			break;
		}
	}


	int count = 0;
	int k = 10;
	
	k = 5;

	while( k < 10 ) 
	{ //@violation ENSURE_SINGLE_ENTRY_AND_EXIT_POINT
EntryPoint: //@b-violation ENSURE_SINGLE_ENTRY_AND_EXIT_POINT
		k++;
	}

	count++;

	if( count < 3 )
	{
		goto EntryPoint; //@b-violation ENSURE_SINGLE_ENTRY_AND_EXIT_POINT
	}

	return 1;
}

