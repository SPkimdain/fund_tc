//@checker DO_NOT_USE_SAME_NAME_IN_NESTED
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
 * 5.2 Identifiers in an inner scope shall not use the same name as an
 *     identifier in an outer scope, and therefore hide that identifier.
 */

/* Included in mc2_0502_1.c and mc2_0502_2.c*/

#ifndef MC2_0502_H
#define MC2_0502_H

extern int local_hide_extern; //@b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
extern void mc2_0502_2 ( void );

#endif

/* end of mc2_0502.h */
