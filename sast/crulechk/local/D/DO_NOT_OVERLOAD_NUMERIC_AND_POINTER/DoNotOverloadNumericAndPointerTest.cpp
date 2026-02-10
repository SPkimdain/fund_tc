//@checker DO_NOT_OVERLOAD_NUMERIC_AND_POINTER

//func-A
int func( char x ) //@b-violationDO_NOT_OVERLOAD_NUMERIC_AND_POINTER
{
	return 10;	
}

//func-B, relation func-A
int func( int *px ) //@violation DO_NOT_OVERLOAD_NUMERIC_AND_POINTER
{
	return *px + 5;
}

//func2-A
void func2( double x, int y ) //@b-violationDO_NOT_OVERLOAD_NUMERIC_AND_POINTER
{
	x = x + 1.0;
}

//func2-B
void func2( char* px, int* py, int z ) //Not Match. argument count is different.
{
	z++;
}

//func2-C, relation func2-A
void func2( float x, char* py ) //@violation DO_NOT_OVERLOAD_NUMERIC_AND_POINTER
{
	x = x + 5.0F;
}

//func3-A
void func3( int x, int y, char z ) //@b-violationDO_NOT_OVERLOAD_NUMERIC_AND_POINTER
{
	x = x + 1;
}

//func3-B, relation func3-A(first argument)
void func3( char* x, double y, double z ) //@violation DO_NOT_OVERLOAD_NUMERIC_AND_POINTER
{
	y++;
}

//func3-C, relation func3-A(second argument)
void func3( double x, int* y, double z ) //@violation DO_NOT_OVERLOAD_NUMERIC_AND_POINTER
{
	x = x + 1.0F;
}

//func4-A
void func4( int x, int y, int z = 10 ) //@b-violationDO_NOT_OVERLOAD_NUMERIC_AND_POINTER
{
	z++;
}

//func4-B, relation func4-A(second argument, z is default argument)
void func4( int* px, int y ) //@violation DO_NOT_OVERLOAD_NUMERIC_AND_POINTER
{
	y++;
}

class TEST
{
public:
	void mFunc( char x );
	void mFunc( int* px );
};

//mfunc-A
void TEST::mFunc( char x ) //@b-violationDO_NOT_OVERLOAD_NUMERIC_AND_POINTER
{
	x = 'y';
}

//mfunc-B, Relation mfunc-A
void TEST::mFunc( int* px ) //@violation DO_NOT_OVERLOAD_NUMERIC_AND_POINTER
{
	int x = *px;
}

int main()
{
	//func( 0 ); //Ambiguous
	func( 1 );
	func( '1' );
	
}
