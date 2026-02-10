//@checker DO_NOT_REUSE_IDENTIFIER_NAME
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
 * 5.7 No identifier name should be reused.
 */


#include "DNRIN_mc2_types.h"
#include "DNRIN_mc2_header.h"
#include "mc2_0507.h"

void mc2_0507_2 ( void )
{
   int32_t i57;

   for ( i57 = 0; i57 < 1; i57++ )
   {
      int32_t reused_name;       /* Local var name vs Local var name */
      enum
      {
         reused_enum
      }
      enum57;
      reused_name = get_int32 ( );
n_lab57:                         /* Not Compliant -
                                    clashes with label in mc2_0507_1.c */
      enum57 = reused_enum;
      use_int32 ( reused_name );
      /* use_enum ( enum57 );   some tools may flag enum_57 as unused */
   }

   for ( i57 = 0; i57 < 1; i57++ )
   {
      int32_t reused_name;       /* Not Compliant - reuse of identifier name */ //@violation DO_NOT_REUSE_IDENTIFIER_NAME
      enum
      {
         reused_enum             /* Not Compliant */ //@violation DO_NOT_REUSE_IDENTIFIER_NAME
      }
      enum57;                    /* Not Compliant */ //@violation DO_NOT_REUSE_IDENTIFIER_NAME
      reused_name = get_int32 ( );
      enum57 = reused_enum;
      use_int32 ( reused_name );
      /* use_enum ( enum57 );   some tools may flag enum57 as unused */
   }
}

/* end of mc2_0507_2.c */
