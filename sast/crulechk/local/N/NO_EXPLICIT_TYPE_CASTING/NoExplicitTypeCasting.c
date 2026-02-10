// @checker NO_EXPLICIT_TYPE_CASTING

#include "custom_typedef.h"

#define TEST_INT	100
#define TEST_CHAR		'M'

void func() 
{
	uint32_t u32a = 100U;
	uint16_t u16a = u32a;	//@violation NO_EXPLICIT_TYPE_CASTING
	float32_t f32a = 1.0f;
	float64_t f64a = 2.0f;
	int32_t s32a ;
	int64_t s64a;
	int16_t mc2_1207_a;
	int16_t mc2_1207_b;
	int16_t mc2_1207_c = mc2_1207_a << mc2_1207_b;

	mc2_1207_c = mc2_1207_a << mc2_1207_b;
	
	int8_t s8a = s32a;	//@violation NO_EXPLICIT_TYPE_CASTING
	uint8_t u8a;

	f32a = f64a;	//@violation NO_EXPLICIT_TYPE_CASTING
	s32a = s64a;	//@violation NO_EXPLICIT_TYPE_CASTING
	u16a = u32a;	//@violation NO_EXPLICIT_TYPE_CASTING
	s64a = s32a;

	s8a = s32a;	//@violation NO_EXPLICIT_TYPE_CASTING
	

}
