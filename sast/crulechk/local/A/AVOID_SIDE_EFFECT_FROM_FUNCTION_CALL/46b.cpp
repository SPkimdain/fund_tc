//@checker AVOID_SIDE_EFFECT_FROM_FUNCTION_CALL





void func1( int x, int y, int& z )
{
	z = 10;
}

int func2( int cond, int *x, int *y, int& z )
{
	if( cond > 0 )
	{
		return *x + *y + z;
	}
	else
	{
		return 0;
	}
}

int func3( int *x )
{
	return *x + 10;
}

class Test1
{
public:
	void set( int _x, int _y )
	{
		this->x = _x;
		this->y = _y;
	}
	int getX( int* cond )
	{
		if( *cond < 10 )
		{
			*cond = 10;
			return 0;
		}

		return x;
	}
private:

	int x;
	int y;
};

class Test2
{
public:
	Test1 getTest1()
	{
		return test1;
	}
private:
	Test1 test1;
};


int main()
{
	int a = 10;
	int b = 5;
	int c = 1;
	Test2 test2;
	Test2* pTest2 = &test2;

	a = test2.getTest1().getX( &a ) + a; //@violation AVOID_SIDE_EFFECT_FROM_FUNCTION_CALL
	
	int total = func2( 10, &a, &a, b ) + func2( 10, &c, &a, a ); //@violation AVOID_SIDE_EFFECT_FROM_FUNCTION_CALL		

	func1( test2.getTest1().getX( &a ), 10, b );

	int k = 10;
	
	a = func3( &k ) + func3( &k ); //@violation AVOID_SIDE_EFFECT_FROM_FUNCTION_CALL	

	if( func3( &k ) + k ) //@violation AVOID_SIDE_EFFECT_FROM_FUNCTION_CALL	
	{
		k = 10;
	}

	/* 논리 연산자로 구분된 경우는 예외로 하도록 함. */
	if( func3( &k ) == 1 && func2( 10, &k, &k, k ) == 10 )
	{
		k = 10;
	}

	return 1;
}
