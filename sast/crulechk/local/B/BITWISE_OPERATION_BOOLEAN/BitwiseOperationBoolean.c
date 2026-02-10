// @checker BITWISE_OPERATION_BOOLEAN

#include "custom_typedef.h"

void BWOPTBOOL_001_function()
{
	int32_t foo1 = 1;
	int32_t foo2 = 2;
	int32_t foo3 = 3;

	bool_t boolean_a;    /* boolean by enforcement */
	bool_t boolean_b;    /* boolean by enforcement */

	
   if ( boolean_a & boolean_b  )		//@violation BITWISE_OPERATION_BOOLEAN
   {
      ;
   }

   if( boolean_a | foo1) //@violation BITWISE_OPERATION_BOOLEAN
   {
   }


	if( (foo1 | (foo2 != 0) ) && (boolean_a & boolean_b) == 0 )	//@violation BITWISE_OPERATION_BOOLEAN
	{
	}


	if((foo1 > foo2) && (foo2 == 3))	{
		/* ......*/
	}

	while( (foo1 == 100) && ( 100 | foo2) )
	{
		/* ....*/
	}

	
	foo3 = foo1 | foo2 ? 1: -1;
}