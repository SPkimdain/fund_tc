//@checker REDUNDANT_CONDITION
//#include <stdint.h>

void RC_function_005(signed char s8a, unsigned short u16a){

	if( u16a > -1 )	//@violation REDUNDANT_CONDITION
	{
		
	}
	
}

