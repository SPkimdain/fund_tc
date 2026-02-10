//@checker BAD_RETURN_TEST

#define RETURN_TEST( x ) returnTestFunc( x )

//Base

int returnTestFunc( int cond )
{
	if( cond > 1 )
	{
		return 0;
	}
	else if ( cond < 1 )
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

enum Decimal
{
	One,
	Two,
	Three
};

Decimal returnTestFunc2( int cond )
{
	if( cond > 1 )
	{
		return One;
	}
	else if ( cond < 1 )
	{
		return Two;
	}
	else
	{
		return Three;
	}
}

void func1()
{
	int x = 0;
	if( returnTestFunc( 5 ) ) //@violation BAD_RETURN_TEST
	{
		x++;
	}

	while( returnTestFunc( 2 ) ) //@violation BAD_RETURN_TEST
	{
		x++;
	}

	for( int i = 0; returnTestFunc( -1 ); i++ ) //@violation BAD_RETURN_TEST
	{
		x++;
	}

	do
	{
	} while( returnTestFunc( 3 ) ); //@violation BAD_RETURN_TEST
}

//Complex

void func2()
{
	int x = 0;

	if( ( ( returnTestFunc( 3 ) ) + 3 ) ) //@violation BAD_RETURN_TEST
	{
		x++;
	}

	if( RETURN_TEST( 5 ) ) //@violation BAD_RETURN_TEST
	{
		x++;
	}

	if( x > 1 && returnTestFunc( 5 ) ) //@violation BAD_RETURN_TEST
	{
		x++;
	}

	if( returnTestFunc2( 5 ) ) //@violation BAD_RETURN_TEST
	{
		x++;
	}
}

//C++Support



namespace 
{
	int x = 0;
	void func3()
	{
		if( returnTestFunc( 5 ) ) //@violation BAD_RETURN_TEST
		{
			x++;
		}
	}
	
	namespace nested
	{
		void func4()
		{
			if( returnTestFunc( 5 ) ) //@violation BAD_RETURN_TEST
			{
				x++;
			}

		}
	}
}



class T0042A
{
public:
	int x;
	void mfunc1()
	{		
		if( returnTestFunc( 5 ) ) //@violation BAD_RETURN_TEST
		{
			x++;
		}
	}

	void mfunc2();
};

void T0042A::mfunc2()
{
	if( returnTestFunc( 5 ) ) //@violation BAD_RETURN_TEST
	{
		x++;
	}
}

void func6()
{
	int x = 0;

	try
	{
		if( returnTestFunc( 5 ) ) //@violation BAD_RETURN_TEST
		{
			x++;
		}

		if( x >= 10 )
		{
			throw x;
		}
	}
	catch( int exp )
	{
		if( returnTestFunc( 5 ) ) //@violation BAD_RETURN_TEST
		{
			x++;
		}
	}
}
