// @checker IMPLICIT_NARROW_INTEGER_CONVERSION

#include "custom_typedef.h"

void func()
{
	int8_t	s8a, s8b, s8r;
	uint8_t	u8a, u8b, u8r;
	uint16_t	u16a, u16b, u16c, u16r;
	int16_t		s16a, s16b;
	uint32_t	u32a, u32b, u32r;
	int32_t	s32a, s32b, s32r;
	int64_t	s64a, s64b, s64r;
	uint64_t	u64a, u64b, u64r;
	my_int_struct	my;
	my_int_struct *my_ptr;
	uint32_t my_array[10];
	uint32_t my_array2[10][10];
	int32_t *i32p;

	s16a = -u16a;  
	s16a = -u8a;    
	s8a = -u8a;
	
	s8a = s16a;	//@violation IMPLICIT_NARROW_INTEGER_CONVERSION
	s8a = (int8_t)s16a;

	s8a = s8b + 100;	/* Compliant */
	s8a = s8a + 150;	//@violation IMPLICIT_NARROW_INTEGER_CONVERSION

	u16r = ( u16a * 3u ) + u16b + u16c;

	*i32p = my_ptr->foo64;	//@violation IMPLICIT_NARROW_INTEGER_CONVERSION
	my_ptr->foo32 = s64a;		//@violation IMPLICIT_NARROW_INTEGER_CONVERSION	
	my_array2[0][0] = u64a;	//@violation IMPLICIT_NARROW_INTEGER_CONVERSION
	my_array[0] = u64a;		//@violation IMPLICIT_NARROW_INTEGER_CONVERSION
	
	my.foo8 = s16a + s16b;	//@violation IMPLICIT_NARROW_INTEGER_CONVERSION
	
	u16a = u32a;			//@violation IMPLICIT_NARROW_INTEGER_CONVERSION
	u16a = get_uint32();	//@violation IMPLICIT_NARROW_INTEGER_CONVERSION
	u16a = get_uint16();
	use_uint16 ( u16a );
	u8a = u8a + get_uint8 ( );                           /* Compliant     */
	s8b = get_int8 ( );

}