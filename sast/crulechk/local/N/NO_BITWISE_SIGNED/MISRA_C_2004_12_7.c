// @checker NO_BITWISE_SIGNED

#include "custom_typedef.h"

void foo()
{
	signed int   s32a, s32b, s32c;
	unsigned int u32a, u32b;
	bool_t b1, b2;
	int32_t a, b;

	if( b1 & b2)
	{
		;
	}

	if(b1 | b2)
	{

	}
	u32a = (unsigned short) ~u32a;
	u32a = ~s32b;		// @violation NO_BITWISE_SIGNED
	s32a = s32b & s32c;	// @violation NO_BITWISE_SIGNED
	s32a = a ^ b;		// @violation NO_BITWISE_SIGNED
	s32a = a | b;		// @violation NO_BITWISE_SIGNED
	s32a &= a;		// @violation NO_BITWISE_SIGNED
	s32a = u32a & u32b;		
}

