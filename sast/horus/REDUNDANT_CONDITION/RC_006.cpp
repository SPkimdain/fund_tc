//@checker REDUNDANT_CONDITION
//#include <stdint.h>

void RC_function_006(signed char s8a, unsigned short u16a){

	if( (s8a < 10) || ( s8a > 5) )	//@violation REDUNDANT_CONDITION
	{
		
	}

}

