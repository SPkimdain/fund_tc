//@checker AVOID_SIDE_EFFECT_IN_EXPRESSION




class Test
{
public:
	Test()
	{
		value = 10;
	}
	const int& operator++(int)
	{
		this->value++;
		return this->value;
	}

private:
	int value;
};

int func(int x, int y)
{
	int z = x + y;
	return z;
}

int func2(bool x)
{
	if( x )
	{
		return 10;
	}
	else
	{
		return 5;
	}
}


int main()
{
	int x = 10;
	int y = 5;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	double a, b, c;
	a = b = c = 1.0; //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION
	Test t;
	
	x = 1 + y++; //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION

	y = arr[x] + x++; //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION

	if( x == y++ ) //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION
	{
		x++, x++, y++, x += 10;
	}
	
	x  = y +
		y++ + //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION
		15 -
		t++; //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION

	x = y + y++ - x-- * //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION
		( y = 10 + y++ ); //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION

	y += ( x = 10 ); //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION

	int k = 5;

	for( x = y++; //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION
		x <= 10 + y++; //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION
		x++, k += k++ ) //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION
	{
	}

	int zz = x++ + y++; //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION

	if( x == 1 &&
		x++ || //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION
		x != 5 )
	{
		int l = 10;
	}
	
	func(x, y++); //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION

	func(func(x,y), func(zz,x));

	func(func(x,y), func(zz,x++)); //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION

	func2( x == 10 && y == 5 );

	func2( x++ == 10 && y == 5 ); //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION

	y = y + y++ + func(x,y); //@violation AVOID_SIDE_EFFECT_IN_EXPRESSION

	return 1;
}
