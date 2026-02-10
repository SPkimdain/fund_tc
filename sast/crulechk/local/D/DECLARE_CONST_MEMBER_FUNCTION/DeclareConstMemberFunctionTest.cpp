//@checker DECLARE_CONST_MEMBER_FUNCTION

using namespace std;

int globalVar = 10;

class C
{
public:
	// should be declared const
	const C& foo() { return * this; } //@violation DECLARE_CONST_MEMBER_FUNCTION
	
	const C& foo2() const { return * this; }
	
	const int& getData() { return m_i; } //@violation DECLARE_CONST_MEMBER_FUNCTION

	const int& getData2() const { return m_i; }
	
	int bar() const { return m_mi; } // ok to declare const

	void mFunc1( int *x );

	void mFunc2( int *x );

	void mFunc3( int *x );

	void mFunc4( int *x ) const;

	void mFunc5( int x );

	void mFunc6( int x );

private:
	int m_i;
	mutable int m_mi;
};

void C::mFunc1( int *x )
{
	int y = 0;

	//modify the externally visible state of the object.
	*x = y;
}


void C::mFunc2( int *x ) //@violation DECLARE_CONST_MEMBER_FUNCTION
{
	int y = 0;

	y++;
	m_mi = 10;
}


void C::mFunc3( int *x )
{
	//modify the externally visible state of the object.
	m_i = 10;
}

//that is same mFunc2 but declare const.
void C::mFunc4( int *x ) const
{
	int y = 0;

	y++;
	m_mi = 10;
}

void C::mFunc5( int x ) //@violation DECLARE_CONST_MEMBER_FUNCTION
{
	x = 10;
}

void C::mFunc6( int x )
{
	//modify the externally visible state of the object.
	globalVar--;
}

int main()
{
	return 1;
}
