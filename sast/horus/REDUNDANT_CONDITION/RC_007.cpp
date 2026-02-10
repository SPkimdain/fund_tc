//@checker REDUNDANT_CONDITION
//#include <stdint.h>

void RC_function_007(signed char s8a){

	for(s8a = 0; s8a < 130; ++ s8a)	//@violation REDUNDANT_CONDITION
	{
	}
}

