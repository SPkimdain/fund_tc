//@checker REDUNDANT_CONDITION
//#include <stdint.h>

void RC_function_004(signed char s8a, unsigned short u16a){
	s8a = (u16a < 0u) ? 0 : 1;	//@violation REDUNDANT_CONDITION	
}


void RC_function_004_b(signed char s8a, short s16a) {
  s8a = (s16a < 0u) ? 0 : 1;	//It's ok.
}
