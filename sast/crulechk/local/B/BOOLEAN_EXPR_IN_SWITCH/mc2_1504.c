//@checker BOOLEAN_EXPR_IN_SWITCH
/*
 * Release Date: 17 JULY 2007
 *
 * MISRA-C:2004 Exemplar Suite
 *
 * Published by
 * MIRA Limited, Watling Street, Nuneaton, Warwickshire CV10 0TU UK
 * www.misra-c.com
 *
 * Copyright MIRA Limited, 2006, 2007.
 *
 * See file READ_ME.txt for full copyright, license and release information.
 */

/*
 * 15.4 A switch expression shall not represent a value that is effectively
 *      boolean.
 */

#include "BEIS_mc2_types.h"
#include "BEIS_mc2_header.h"

void mc2_1504 ( void )
{
   int16_t mc2_1504_a = get_int16 ( );

   switch ( mc2_1504_a == 0 )                           /* Not Compliant */ //@violation BOOLEAN_EXPR_IN_SWITCH
   {
      case 0:
      {
         use_int16 ( mc2_1504_a );
         break;
      }
      default:
      {
         use_int16 ( mc2_1504_a );
         break;
      }
   }
}


/* end of mc2_1504.c */
