
//@checker BAD_EQUALITY_EXPRESSION.FLOAT

float getFloat( float x );

#define FLOAT_VALUE 1.0F
#define GET_FLOAT( x ) getFloat( x )

//Base

void func1( float f, float g )
{
	float z;
	int x = 0;

	if( f == g ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
	{
		x++;
	}

	for( float k = 0; k == f; k++ ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
	{
		x++;
	}

	while( f == g ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
	{
		f = f + 1.0F;
	}

	do
	{
		f = f + 0.5F;
	}while( f == g ); //@violation BAD_EQUALITY_EXPRESSION.FLOAT

	z = f == g ? 1.0F : 0.5F; //@violation BAD_EQUALITY_EXPRESSION.FLOAT

	if( ( f > g ) || ( f < g ) ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
	{
		x++;
	}
	
	if( ( f >= g ) && ( f <= g ) ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
	{
		x++;
	}
	
	if( f != g ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
	{
		x--;
	}
	
}

//Complex

float getFloat( float x )
{
	return x + 1.0F;
}

void func2( float f, float g, long double h )
{
	double z = 5.5F;
	int x = 0;
	if( f == h ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
	{
		x++;
	}

	if( getFloat( 5.0F ) == getFloat( 4.9F ) ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
	{
		x++;
	}


	if( ( 1 + ( 4.0F + f ) ) == z ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
	{
		x++;
	}

	int y = 10;
	if( ( float )y == g ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
	{
		x++;
	}

	if( FLOAT_VALUE == g ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
	{
		x++;
	}
	
	if( GET_FLOAT( f ) == g ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
	{
		x++;
	}

	float *pf = &f;
	float *pg = &g;
	if( *pf == *pg ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
	{
		x++;
	}


	float **ppf = &pf;
	float **ppg = &pg;
	if( **ppg == **ppf ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
	{
		x++;
	}

}

//C++Support


namespace 
{
	float h = 10.0F;
	float i = 5.0F;
	int x = 0;

	void func3( float f, float g )
	{
		
		if( h == i ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
		{
			x++;
		}
	}
	
	namespace nested
	{
		void func4( float f, float g )
		{
			if( h == g ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
			{
				x++;
			}
		}
	}
}



class T0038A
{
public:
	float h;
	int x;

	void mfunc1( float f, float g )
	{
		
		if( this->h == f ) //@violation BAD_EQUALITY_EXPRESSION.FLOAT
		{
			this->x++;
		}
	}

	void mfunc2( float f, float g );
};

void T0038A::mfunc2( float f, float g )
{	
	if( this->h == f )  //@violation BAD_EQUALITY_EXPRESSION.FLOAT
	{
		this->x++;
	}
}


void func6( float f, float g )
{
	int x = 0;

	try
	{
		if( f == g )  //@violation BAD_EQUALITY_EXPRESSION.FLOAT
		{
			throw f;
		}
	}
	catch( float exp )
	{
		if( exp == g )  //@violation BAD_EQUALITY_EXPRESSION.FLOAT
		{
			x++;
		}
	}
}
