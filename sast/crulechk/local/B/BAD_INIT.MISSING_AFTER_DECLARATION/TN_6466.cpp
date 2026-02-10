//@checker BAD_INIT.MISSING_AFTER_DECLARATION
#include <stdarg.h>
#define TEST int var;

void his_30() {
	TEST
} 

int Summation( int count, ... )
{
    int i = 0, sum = 0;
    va_list marker;

    va_start( marker, count );
    for( i = 0; i < count; i++ )
        sum += va_arg( marker, int );

    va_end( marker );

    return sum;
}

