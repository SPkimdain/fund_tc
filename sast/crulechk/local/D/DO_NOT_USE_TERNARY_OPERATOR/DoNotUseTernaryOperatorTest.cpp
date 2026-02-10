//@checker DO_NOT_USE_TERNARY_OPERATOR


bool foo( int x )
{
	return x == 1 ? true : false; //@violation DO_NOT_USE_TERNARY_OPERATOR
}

int main()
{
	int x = 10;
	int y = x == 10 ? 5 : 3; //@violation DO_NOT_USE_TERNARY_OPERATOR

	foo( y == 5 ? 7 : 3 ); //@violation DO_NOT_USE_TERNARY_OPERATOR

}
