//@checker ONLY_DECLARE_TRIVIAL_FUNCTINS_INLINE

class NonCorrect
{
public:
	NonCorrect()
	{
		nc = 0;
	}
	bool foo( int x )
	{
		if( x > 0 )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool bar( int x ) //@violation ONLY_DECLARE_TRIVIAL_FUNCTINS_INLINE
	{
		while( x != 0 )
		{
			x = x - 1;
		}
		
		return false;
	}

	int car( int x );
	int car2( int x );

private:
	int nc;	
};

inline int NonCorrect::car( int x )
{
	return x + nc;
}

inline int NonCorrect::car2( int x ) //@violation ONLY_DECLARE_TRIVIAL_FUNCTINS_INLINE
{
	for( int i = 0; i < x; i++ )
	{
		nc = nc + 10;
	}

	return nc;
}

inline void func1( int x ) //@violation ONLY_DECLARE_TRIVIAL_FUNCTINS_INLINE
{
	do
	{
		if( x > 10 )
		{
			break;
		}
		x++;
	}while(1);
}

inline bool isCheck( int x ) //@violation ONLY_DECLARE_TRIVIAL_FUNCTINS_INLINE
{
	if( x == 10 )
	{
		return true;
	}
	else if( x < 10 )
	{
		return isCheck( x + 1 );
	}
	else
	{
		return false;
	}
}

int main()
{

	return 1;
}
