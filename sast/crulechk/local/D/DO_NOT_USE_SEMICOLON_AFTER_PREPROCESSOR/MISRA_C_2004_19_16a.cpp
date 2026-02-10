//@checker DO_NOT_USE_SEMICOLON_AFTER_PREPROCESSOR

#include <stdio.h>; //@violation DO_NOT_USE_SEMICOLON_AFTER_PREPROCESSOR

#define TEST 1234
#ifdef TEST; //@violation DO_NOT_USE_SEMICOLON_AFTER_PREPROCESSOR

int main()
{
	return 1;
}

#else; //@violation DO_NOT_USE_SEMICOLON_AFTER_PREPROCESSOR

int foo( int x )
{
	return x + 10;
}

#endif; //@violation DO_NOT_USE_SEMICOLON_AFTER_PREPROCESSOR

#define TEST2 10

#ifdef TEST
#endif

#if TEST2 > 8

#endif

