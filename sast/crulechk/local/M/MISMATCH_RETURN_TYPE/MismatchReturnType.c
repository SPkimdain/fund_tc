// @checker MISMATCH_RETURN_TYPE
#define NULL 0
#include "custom_typedef.h"

char* foo_pointer()
{
	return NULL;
}

uint16_t foo_complex2 ( uint16_t x, uint16_t y )
{
	return x + 1000u;
}

uint16_t foo_complex1 ( uint16_t x, uint16_t y )
{
	return x + y;
}


float64_t foo1() {
	return 1L;                       //@violation	MISMATCH_RETURN_TYPE
}

int32_t foo2(){
	return 1.0f;		//@violation	MISMATCH_RETURN_TYPE
}

int16_t bar(){
	return 100U;		//@violation	MISMATCH_RETURN_TYPE
}

int32_t bar2(){
	return 1000000L;	//@violation	MISMATCH_RETURN_TYPE
}

float32_t func(float64_t f64a) {
	return (f64a);                       //@violation	MISMATCH_RETURN_TYPE
}

int8_t foo(){
	int32_t		tmp = 1;
	return tmp;		//@violation	MISMATCH_RETURN_TYPE
}