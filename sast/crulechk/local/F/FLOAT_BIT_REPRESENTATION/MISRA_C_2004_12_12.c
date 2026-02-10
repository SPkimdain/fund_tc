// @checker FLOAT_BIT_REPRESENTATION

#include "custom_typedef.h"

void float_bit_operation()
{
	 float32_t mc2_1212_b;
	 
   uint32_t mc2_1212_c;
	union /* use of union is also a violation of 18.4 */
   {
      float32_t real;	//@b-violation FLOAT_BIT_REPRESENTATION
      uint32_t decimal;
   } mc2_1212_a;

	 mc2_1212_c = * (uint32_t *) &mc2_1212_b; //@violation FLOAT_BIT_REPRESENTATION
	mc2_1212_a.decimal ++;     //@violation FLOAT_BIT_REPRESENTATION

     

}
