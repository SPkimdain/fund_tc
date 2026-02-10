//@checker DO_NOT_ALTER_CONTROL_VARIABLE_MORE_THAN_ONCE

int DNACVMTO_func1()
{
	for( int i = 0; i < 10; ++i ) // @violation DO_NOT_ALTER_CONTROL_VARIABLE_MORE_THAN_ONCE
	{
		++i;
	}
	
	int j = 0;	
	for( int i = 0; i < 10 && j < 10 ; ++i, ++j ) // @violation DO_NOT_ALTER_CONTROL_VARIABLE_MORE_THAN_ONCE
	{
		//k++;
		++i;
	}

	for( int i = 0, k = 0; i< 10; ++i, ++k )
	{
		k++;
		k++;
		j++;
	}

	int x = 0, y = 1;

	do // @violation DO_NOT_ALTER_CONTROL_VARIABLE_MORE_THAN_ONCE
	{
		x++;
		x++;
	} while( x != 10 );

	x = 0;

	while( x != 10 && y != 5) // @violation DO_NOT_ALTER_CONTROL_VARIABLE_MORE_THAN_ONCE
	{
		x++;
		y++;
		x++;
		y++;
	}
	return 0;
}
