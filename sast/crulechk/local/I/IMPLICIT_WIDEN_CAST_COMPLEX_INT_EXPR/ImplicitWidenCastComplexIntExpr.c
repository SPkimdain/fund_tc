// @checker IMPLICIT_WIDEN_CAST_COMPLEX_INT_EXPR

#include "custom_typedef.h"

void func()
{
	int32_t		s32a, s32b, s32r;
	int16_t		s16a, s16b;
	uint16_t		u16a, u16b;
	int8_t		s8a, s8b;
	uint64_t	u64a, u64b;
	int64_t		s64a, s64b, s64r;

	my_int_struct	my;
	my_int_struct *my_ptr;
	int32_t my_array[10];
	int32_t my_array2[10][10];
	int32_t *i32p;

	s64r = my.foo32 + s32b;			//@violation IMPLICIT_WIDEN_CAST_COMPLEX_INT_EXPR
	s64r = my_ptr->foo32 + s32b;	//@violation IMPLICIT_WIDEN_CAST_COMPLEX_INT_EXPR
    s64r = s64r + (s32a + s32b);    //@violation IMPLICIT_WIDEN_CAST_COMPLEX_INT_EXPR
	s64r = get_int32 ( ) + s32b; //@violation IMPLICIT_WIDEN_CAST_COMPLEX_INT_EXPR
    s32r = s32a * s32b;
    s64r = s64a + s32b;
    s64r = s64a + ( (int64_t) s32a * s32b ); 
	s64r = s64a + s32b; 

}