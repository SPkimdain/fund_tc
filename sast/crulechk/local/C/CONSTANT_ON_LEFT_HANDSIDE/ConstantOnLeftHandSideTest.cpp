//@checker CONSTANT_ON_LEFT_HANDSIDE

int getValue()
{
	return 15;
}

int main()
{
	int i = 0;
	int a = getValue();
	if ( a == 10 ) // @violation CONSTANT_ON_LEFT_HANDSIDE
	{
		int x = 0;
	}
	if ( 10 == a ) // prefer: compiler will warn if '=' is used
	{
		int x = 0;
	}

	while( !a == 10 ) // @violation CONSTANT_ON_LEFT_HANDSIDE
	{
		i++;
	}

	if( ( a ) == 10 ) // @violation CONSTANT_ON_LEFT_HANDSIDE
	{
		i++;
	}
  
  if(a == i) { //It's ok.
    i++;
  }
	
}

