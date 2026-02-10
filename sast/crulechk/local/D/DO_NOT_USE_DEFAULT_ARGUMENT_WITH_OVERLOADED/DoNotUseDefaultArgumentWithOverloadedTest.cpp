//@checker DO_NOT_USE_DEFAULT_ARGUMENT_WITH_OVERLOADED

// Avoid, calls to foo with 1 arg are ambiguous
//
void foo( int x )
{
	x++;
}

void foo( int x, char c = 10 ) //@violation DO_NOT_USE_DEFAULT_ARGUMENT_WITH_OVERLOADED
{
	x++;
}
// Prefer, bar(int) is implemented in terms of bar( int, char )
//

void bar( int x, char c )
{
	x++;
}

void bar( int x )
{
	x++;
}

// Prefer, default arg is okay here as there is no overloads of car
//
void car( int x, char c = 10 )
{
	x++;
}

class TEST2
{
public:
	void mfunc( int x )
	{
		x++;
	}

	void mfunc( int x, char c = 10 ) //@violation DO_NOT_USE_DEFAULT_ARGUMENT_WITH_OVERLOADED
	{
		x++;
	}

	void mfunc2( int x )
	{
		x++;
	}

	void mfunc2( int x, char c )
	{
		x++;
	}

	void mfunc3( int x, char c = 10 )
	{
		x++;
	}
};

int main()
{
	return 1;
}
