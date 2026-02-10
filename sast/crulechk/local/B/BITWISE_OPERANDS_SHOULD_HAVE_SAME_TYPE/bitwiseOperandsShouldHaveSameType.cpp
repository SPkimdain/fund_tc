// @checker BITWISE_OPERANDS_SHOULD_HAVE_SAME_TYPE
#include "custom_typedef.h"

int main()
{
	uint8_t uTmp8 = ~(0x10);   //unsigned char

	uint8_t uNum8;     //unsigned char
	uint16_t uNum16;   //unsigned short
	uint32_t uNum32;   //unsigned int
	uint64_t uNum64;   //unsigned long
	int8_t sNum8;      //signed char
	
	uNum8 ^= uTmp8;            
	uNum8 = uNum8^uTmp8;      
	
	uNum8 ^= uNum16;          //@violation BITWISE_OPERANDS_SHOULD_HAVE_SAME_TYPE
	uNum8 = uNum8^uNum16;     //@violation BITWISE_OPERANDS_SHOULD_HAVE_SAME_TYPE

	uNum8 &= sNum8;           //@violation BITWISE_OPERANDS_SHOULD_HAVE_SAME_TYPE
	uNum16 = uNum16 | sNum8;  //@violation BITWISE_OPERANDS_SHOULD_HAVE_SAME_TYPE

	uNum16 ^= (3);        
	uNum8 ^= 5;          
	uNum16 = uNum16 | 5; 

	return 0;
}