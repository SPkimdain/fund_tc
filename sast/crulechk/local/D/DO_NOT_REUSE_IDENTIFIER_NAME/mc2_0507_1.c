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

void mc2_0507 ( void )
{
   static struct air_data
   {
      uint16_t speed;
      uint16_t air_speed;
   } * air;
   static struct gnd_data
   {
      uint16_t speed;      /* Not Compliant - speed is reused */ //@violation DO_NOT_REUSE_IDENTIFIER_NAME
      uint16_t gnd_speed;  /* Compliant */
   } * gnd;

   gnd->speed = get_uint16 ( );
   gnd->gnd_speed = get_uint16 ( );
n_lab57:                   /* Not Compliant -
                              clashes with label in mc2_0507_2.c */
   air->speed = gnd->speed;
   air->air_speed = gnd->gnd_speed;

   /* Usage */

   use_uint16 ( gnd->speed );
   use_uint16 ( gnd->gnd_speed );
   use_uint16 ( air->speed );
   use_uint16 ( air->air_speed );

   /* Calling functions with external linkage */

   mc2_0507_2();
}

/* end of mc2_0507_1.c */
