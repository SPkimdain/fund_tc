//@checker EMPTY_ARRAY_SIZE
#include "custom_typedef.h"

#define REGIST_STR(var, str) char_t var[] = str

void func(uint32_t arr1[])
{
	int32_t arr[] = {0,1,2};//@violation EMPTY_ARRAY_SIZE
	//int32_t arr3[];
	char_t arr2[] = "asdf";	//@violation EMPTY_ARRAY_SIZE

  REGIST_STR(arr3, "test"); //It's ok. skip a macro.
}
