//@checker USE_CONST_WITH_MACRO
#include "use_const_with_macro.h"

#define TESTA 30


void function(int length){
	if(length < 20){ //@violation USE_CONST_WITH_MACRO
		/* Do something */
	}
	else if (length < TESTA) 
	{

	}
	else if (length < TESTB)//@violation USE_CONST_WITH_MACRO
	{

	}
	else if (length < 30) //@violation USE_CONST_WITH_MACRO
	{

	}
	else if (length < TESTB &&  length > TESTB ) //@violation USE_CONST_WITH_MACRO
	{
		
	}

	else
	{

	}
} 