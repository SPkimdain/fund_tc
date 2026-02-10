// @checker ALREADY_DEFINE_IDENTIFIER

#include <stdio.h>
#include <stdlib.h>
#include "MISRA_C_2004_19_11.h"

 #if 0 //It's ok.
 #endif 
 
 #if 1 //It's ok.
 #endif

#if X == 1 // @violation ALREADY_DEFINE_IDENTIFIER
	#define NUMX 1 
#elif 	X == 2 // @violation ALREADY_DEFINE_IDENTIFIER
	#define NUMX 2
#else
	#define NUMX 3
#endif

int ADI_func1()
{
	return 1;
}
