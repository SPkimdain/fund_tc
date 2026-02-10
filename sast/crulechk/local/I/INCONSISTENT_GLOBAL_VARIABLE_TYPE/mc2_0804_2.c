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

extern int32_t incompatible_int;

void mc2_0804_1 ( void )
{
   use_int32  ( compatible_int );
   use_char   ( compatible_char [ 1 ] );
   use_uint16 ( compatible_ushort );

   incompatible_int = 2;
}


/* end of mc2_0804_2.c */
