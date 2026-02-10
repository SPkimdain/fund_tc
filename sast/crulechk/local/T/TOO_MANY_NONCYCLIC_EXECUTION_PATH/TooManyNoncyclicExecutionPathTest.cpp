//@checker TOO_MANY_NONCYCLIC_EXECUTION_PATH

int normalFunction( int x, int y )
{
	if( x == 1 )
	{
		switch( y )
		{
		case 1:
			break;
		case 2:
			break;
		default:
			break;
		}
	}
	else if( x == 2 )
	{
		return 10;
	}

	return 1;
}

int executionPath( int input1, int input2 ) 
{ //@violation TOO_MANY_NONCYCLIC_EXECUTION_PATH
	int x = 0;
	int y = 1;
	int z = 2;
	int a = 3;
	int b = 4;
	int c = 5;

	if( input1 == 1 )
	{
		if( x != 0 )
		{
			switch( input2 )
			{
			case 1:
				return 3;
				break;
			case 2:
				return 3;
				break;
			case 3:
				return 5;
				break;
			case 4:
				return 10;
				break;
			case 5:
				return 11;
				break;
			case 21:
				return 14;
				break;
			case 6:
				return 15;
				break;
			case 7:
				return 1;
				break;
			case 8:
				if( input1 == 10 )
				{
					while( y != 0 )
					{
						y--;
					}
				}
				else if( input1 > 12 )
				{
					for( int i = 0; i < 10; i++ )
					{
						if( a == b )
						{
							if( b == c )
							{
								if( c == input1 )
								{
									return 5;
								}
							}
						}
					}
				}
				break;
			case 9:
				if( input1 == 15 )
				{
					while( y != 0 )
					{
						y--;
					}
				}
				else if( input1 > 12 )
				{
					for( int i = 0; i < 10; i++ )
					{
						if( a == b )
						{
							if( b == c )
							{
								if( c == input1 )
								{
									return 5;
								}
							}
						}
					}
				}
				break;
			case 10:
				if( input1 == 20 )
				{
					while( y != 0 )
					{
						y--;
					}
				}
				else if( input1 > 12 )
				{
					for( int i = 0; i < 10; i++ )
					{
						if( a == b )
						{
							if( b == c )
							{
								if( c == input1 )
								{
									return 5;
								}
							}
						}
					}
				}
				break;
			case 11:
				if( input1 == 25 )
				{
					while( y != 0 )
					{
						y--;
					}
				}
				else if( input1 > 12 )
				{
					for( int i = 0; i < 10; i++ )
					{
						if( a == b )
						{
							if( b == c )
							{
								if( c == input1 )
								{
									return 5;
								}
							}
						}
					}
				}
				break;
			case 12:
				return 10;
				break;
			case 13:
				return 5;
				break;
			case 14:
				return 3;
				break;
			case 15:
				if( x == y )
				{
					return 111;
				}
				break;
			case 16:
				switch( x )
				{
				case 100:
					return 5;
					break;
				case 200:
					return 10;
					break;
				case 300:
					return 100;
					break;
				default:
					break;
				}
				break;
			case 17:
				return 1;
				break;
			case 18:
				return 0;
				break;
			case 19:
				return -1;
				break;
			case 20:
				return 15;
				break;
			default:
				return 1000;
				break;
			}
		}	
	}

	for( int i = 0; i < 10; i++ )
	{
		input1 *= 10;
		if( input1 == 10 )
		{
			if( input2 == 100 )
			{
				if( a == b )
				{
					if( b == c )
					{
						if( c == z )
						{
							return 100;
						}
					}
				}
			}
		}
	}
	return 1;
}
