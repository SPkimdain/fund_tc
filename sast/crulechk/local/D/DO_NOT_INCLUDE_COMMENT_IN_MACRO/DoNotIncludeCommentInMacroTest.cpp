//@checker DO_NOT_INCLUDE_COMMENT_IN_MACRO


#define TESTX /* TEST */ 1 //@violation DO_NOT_INCLUDE_COMMENT_IN_MACRO

#define TEST(x, y) if( ( x ) ) \
	y++; \
	x = x + y //@violation DO_NOT_INCLUDE_COMMENT_IN_MACRO

#define TEST2(x, y) if( ( x ) ) \
	y++; \
	x = x + y;

int main()
{
	int x = TESTX;
	int y = 10;

	TEST( x, y );

	TEST2( x, y );
}
