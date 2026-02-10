// @checker UNARY_NEGATIVE_OP_ON_UNSIGNED

#include "custom_typedef.h"

struct _test{
	uint32_t	u32a;
	int32_t		s32a;

};

unsigned int testrun_UNOO ()
{
	return 1;
}

void func()
{
	signed char s8a;
	unsigned char u8a;
	short s16a;
	unsigned short u16a;
	signed int     s32a;
	unsigned int   u32a;
	uint32_t u32b;
	long s64a;
	int64_t s64b;
	unsigned int u64a;
	uint64_t	u64b;
	struct _test test;
	
	s64a = - testrun_UNOO (); // @violation UNARY_NEGATIVE_OP_ON_UNSIGNED
	s64a = - test.u32a;	// @violation UNARY_NEGATIVE_OP_ON_UNSIGNED
	s64a = -test.u32a;	// @violation UNARY_NEGATIVE_OP_ON_UNSIGNED
	s8a = -u8a;	// @violation UNARY_NEGATIVE_OP_ON_UNSIGNED
	s16a = -u16a;	// @violation UNARY_NEGATIVE_OP_ON_UNSIGNED
	s32a = -u32a;	// @violation UNARY_NEGATIVE_OP_ON_UNSIGNED
	s32a = -(u32b);	// @violation UNARY_NEGATIVE_OP_ON_UNSIGNED	
	
	s64a = -u64a;	// @violation UNARY_NEGATIVE_OP_ON_UNSIGNED
	s64a = -(u64b);	// @violation UNARY_NEGATIVE_OP_ON_UNSIGNED
}
