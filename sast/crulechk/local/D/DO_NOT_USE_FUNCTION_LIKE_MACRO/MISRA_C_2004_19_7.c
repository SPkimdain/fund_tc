// @checker DO_NOT_USE_FUNCTION_LIKE_MACRO

#define TEST 1
#define ADD(X,Y) X + Y; // @violation DO_NOT_USE_FUNCTION_LIKE_MACRO

void main()
{
	int a = 1;
	int b = 2;
	int c = 0;

	c = ADD(a,b);

}
