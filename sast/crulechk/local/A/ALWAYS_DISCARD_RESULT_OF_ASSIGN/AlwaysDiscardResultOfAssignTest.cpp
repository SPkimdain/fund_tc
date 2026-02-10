//@checker ALWAYS_DISCARD_RESULT_OF_ASSIGN

int main( int argc, char** argv )
{
	int i = 1;
	int j = 2;
	// Confusing use of assignment operator, always discard the result

	if ( ( j = i ) == 1 ) // @violation ALWAYS_DISCARD_RESULT_OF_ASSIGN
	{
		i = 1;
	}

	while( ( j = i ) != 1 ) // @violation ALWAYS_DISCARD_RESULT_OF_ASSIGN
	{
		i = 1;
	}

	int k = 0;

	for( int l = 0; ( l = i + 1 ) < 10; l++ ) // @violation ALWAYS_DISCARD_RESULT_OF_ASSIGN
	{
		k = 5;		
	}

	// Prefer to write
	//
	j = i;
	if ( 1 == j )
	{
		j = 1;
	}
	return 1;
}
