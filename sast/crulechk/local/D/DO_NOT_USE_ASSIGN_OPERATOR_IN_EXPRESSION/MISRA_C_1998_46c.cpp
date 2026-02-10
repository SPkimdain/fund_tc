//@checker DO_NOT_USE_ASSIGN_OPERATOR_IN_EXPRESSION

class Test
{
public:
	Test() : x(0), y(0) {}
	Test( int _x, int _y ) : x(_x), y(_y) {}

	Test& operator=( const Test& lhs )
	{
		x = lhs.x;
		y = lhs.y;
		return *this;
	}

private:
	int x;
	int y;
};

int main()
{
	int x = 10;
	int y = x = 5; //@violation DO_NOT_USE_ASSIGN_OPERATOR_IN_EXPRESSION

	if( y = 10 ) //@violation DO_NOT_USE_ASSIGN_OPERATOR_IN_EXPRESSION
	{
		int z = 3;
	}

	while( y = 5 && x == 10 ) //@violation DO_NOT_USE_ASSIGN_OPERATOR_IN_EXPRESSION
	{
		y++;
	}

	Test st1;
	Test st2;
	Test st3;
	st2 = st1;

	st3 = st2 = st1; //@violation DO_NOT_USE_ASSIGN_OPERATOR_IN_EXPRESSION
	st3 = st2;
}
