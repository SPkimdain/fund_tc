//@checker AVOID_SIDE_EFFECT_IN_PARAMETERS




int add( int x, int y)
{
	return x + y;
}

int sum( int x, int y, int z )
{
	return x + y + z;
}

class Test
{
public:
	Test() : x(0) {}

	void setX( int _x )
	{
		this->x = _x;
	}

	int getX() { return x; }

	Test& operator=( const Test& rhs )
	{
		x = rhs.x;
		return *this;
	}

	Test& operator++(int)
	{
		x++;
		return *this;
	}
private:
	int x;
};


int tFunc( Test x, Test y )
{
	return x.getX() + y.getX();
}

int main()
{
	int x = 5;
	int y = 10;
	
	add( x++, x );//@violation AVOID_SIDE_EFFECT_IN_PARAMETERS
	sum( x++, x, 5 ) ; //@violation AVOID_SIDE_EFFECT_IN_PARAMETERS
	Test t1;
	Test t2;
	t2.setX( 10 );
	t1 = t2; 

	tFunc( t1++, t1 ); //@violation AVOID_SIDE_EFFECT_IN_PARAMETERS

	return 1;
}

