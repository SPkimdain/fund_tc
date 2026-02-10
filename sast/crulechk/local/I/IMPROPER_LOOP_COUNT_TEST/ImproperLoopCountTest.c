//@checker IMPROPER_LOOP_COUNT_TEST

#include "custom_typedef.h"

void improper_loop_count_test()
{

	uint16_t  mc2_1305_var1;
   uint16_t  mc2_1305_var2;
   uint16_t  mc2_1305_var3;

   for ( mc2_1305_var2 = 0, mc2_1305_var3 = 0;
         mc2_1305_var1 < 48U;	
         mc2_1305_var2++ )
   {      
      ;
   }
	
   for ( mc2_1305_var2 = 0;
         mc2_1305_var1 < 48U;		//@violation IMPROPER_LOOP_COUNT_TEST
         mc2_1305_var2++ )
   {      
      ;
   }

}