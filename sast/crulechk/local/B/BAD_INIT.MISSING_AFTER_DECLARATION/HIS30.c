//@checker BAD_INIT.MISSING_AFTER_DECLARATION
#include <stdio.h>
#include <stdarg.h>

#define TEST 			\
	int aa;					\
	int test;			\
	int bb;

void his_30() {
	int var; //@violation BAD_INIT.MISSING_AFTER_DECLARATION
	
} 

int Summation( int count, ... )
{
    int i = 0, sum = 0;
    va_list marker;
	//TEST;
    va_start( marker, count );
    for( i = 0; i < count; i++ )
        sum += va_arg( marker, i );

    va_end( marker );

    return sum;
}

