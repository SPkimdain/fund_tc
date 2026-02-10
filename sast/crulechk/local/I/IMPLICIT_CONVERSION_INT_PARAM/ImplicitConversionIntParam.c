// @checker IMPLICIT_CONVERSION_INT_PARAM

#include "custom_typedef.h"

void func()
{
	int32_t		s32a, s32b;
	int16_t		s16a, s16b;
	uint16_t		u16a, u16b;
	int8_t		s8a, s8b;
	uint64_t	u64a, u64b;
	my_int_struct	my;
	my_int_struct *my_ptr;
	int32_t my_array[10];
	int32_t my_array2[10][10];
	int32_t *i32p;

	use_int64(s32a);		//@violation IMPLICIT_CONVERSION_INT_PARAM
	use_int32(s16a);		//@violation IMPLICIT_CONVERSION_INT_PARAM
	use_uint32(s8a);	//Violation, but not this checker
	use_uint32(u16a);	//@violation IMPLICIT_CONVERSION_INT_PARAM
	use_int32(s32a);
	use_uint32(u64a);
	use_int64((int64_t)s32a);

	use_uint32(my.foo16u);	//@violation IMPLICIT_CONVERSION_INT_PARAM
	use_int64(my_ptr->foo32);	//@violation IMPLICIT_CONVERSION_INT_PARAM
	use_int64(my_array[0]);	//@violation IMPLICIT_CONVERSION_INT_PARAM
	use_int64(my_array2[0][0]);	//@violation IMPLICIT_CONVERSION_INT_PARAM
}