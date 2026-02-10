//@checker INCONSISTENT_GLOBAL_VARIABLE_TYPE

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
 * 8.4 If objects or functions are declared more than once their types shall be
 *     compatible.
 */

/* This file also contains violations of Rule 8.8 */


#include "IGVT_mc2_types.h"
#include "IGVT_mc2_header.h"
#include "mc2_0804.h"

plain32int compatible_int = 0;
char_t compatible_char [ 5 ] = { '0', '0', '0', '0', '0' };
uint16_t compatible_ushort = 0U;

char_t incompatible_int = '0';       /* Not Compliant but it can't check the alarm using the cruletest. */

void mc2_0804 ( void )
{
   use_int32  ( compatible_int );
   use_char   ( compatible_char [ 0 ] );
   use_uint16 ( compatible_ushort );

   use_char ( incompatible_int );

   /* Calling functions with external linkage */

   mc2_0804_1 ( );
}

/* end of mc2_0804_1.c */
