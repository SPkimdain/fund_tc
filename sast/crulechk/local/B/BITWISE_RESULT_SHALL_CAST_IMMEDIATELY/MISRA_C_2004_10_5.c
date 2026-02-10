// @checker BITWISE_RESULT_SHALL_CAST_IMMEDIATELY

#include "custom_typedef.h"

void func()
{
	unsigned char port = 0x5aU;
	unsigned char result_8;
	unsigned short result_16;
	unsigned short mode;
	unsigned char result_8_1 = (~port) >> 4; //@violation BITWISE_RESULT_SHALL_CAST_IMMEDIATELY	
	unsigned short result_16_1 = ((unsigned short)((unsigned short)port << 4) & mode) >> 6; 
	int foo;
	unsigned int bar;

	uint8_t u8a = 10;
	uint8_t u8r = 0;
	uint16_t u16a = 10;
	uint16_t u16r = 0;

	u8r = ( 0x12U << 2 ) >> 4;          //@violation BITWISE_RESULT_SHALL_CAST_IMMEDIATELY	
	u16r = ~0x1234U >> 4;               //@violation BITWISE_RESULT_SHALL_CAST_IMMEDIATELY	
	u8r = ~u8a >> 4;                     //@violation BITWISE_RESULT_SHALL_CAST_IMMEDIATELY	
	u16r = ( u16a << 2 ) >> 4;          //@violation BITWISE_RESULT_SHALL_CAST_IMMEDIATELY	
	

	result_8 = (~port) >> 4; //@violation BITWISE_RESULT_SHALL_CAST_IMMEDIATELY	
	result_8 = ((unsigned char)(~port)) >> 4 ; 
	result_16 = ((port << 4) & mode) >> 6; //@violation	BITWISE_RESULT_SHALL_CAST_IMMEDIATELY
	foo = (~port) >> 4;
	bar = (~port) >> 4;
	
	result_16 = ((unsigned short)(~(unsigned short)port)) >> 4 ;
	result_16 = ((unsigned short)((unsigned short)port << 4) & mode) >> 6; 
}
