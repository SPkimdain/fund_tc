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

/* This rule is superceded by rule 8.8 */

/* Included in mc2_0804_1.c and mc2_0804_2.c */

#ifndef MC2_0804_H
#define MC2_0804_H

typedef int plain32int;

typedef unsigned short plain16uint;

extern compatible_int;                    /* Not Compliant 8.2 */
extern char_t compatible_char [ ];        /* Not Compliant 8.12 */
extern plain16uint compatible_ushort;

extern void mc2_0804_1 ( void );

#endif

/* end of mc2_0804.h */

