// @checker POINTER_ARITHMETIC_NOT_ON_ARRAY
#include "custom_typedef.h"

struct test_struct{
	uint32_t* index;
	uint32_t dummy;
};

void foo(uint32_t* ptr)
{
	struct test_struct test1;
	uint32_t arr[10] ={0,};
	uint32_t* p = ptr + 10; //@violation POINTER_ARITHMETIC_NOT_ON_ARRAY	
	p = test1.index + (200 / 40);	//@violation POINTER_ARITHMETIC_NOT_ON_ARRAY	
	p = ptr + 100;    //@violation POINTER_ARITHMETIC_NOT_ON_ARRAY	
	p += 3;    //@violation POINTER_ARITHMETIC_NOT_ON_ARRAY	
	ptr++;
	p++;
	p = arr + 5;
}