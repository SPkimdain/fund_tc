//@checker USE_UNSIGNED_INT_ON_DIVISION

#include "custom_typedef.h"

void foo()
{
	int result;
	int i = 6;
	int32_t  x = 10;
	unsigned int ui = 3;
	result = i / ui; //@violation USE_UNSIGNED_INT_ON_DIVISION
	result = x / ui;	//@violation USE_UNSIGNED_INT_ON_DIVISION
}

