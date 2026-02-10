//@checker DO_NOT_USE_IF_DIRECTIVE

#define TEST 10
#if TEST > 50 //@violation DO_NOT_USE_IF_DIRECTIVE

#define TEST2 10

#else

#define TEST2 20

#endif //TEST > 50

#include <stdio.h>

int main()
{
	printf( "%d", TEST2 );
	
	return 1;
}

