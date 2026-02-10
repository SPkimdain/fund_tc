//@checker DO_NOT_USE_STDARG_FEATURE
/*
 * Release: 2014-01-13
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

/*
 * R.17.1
 *
 * The features of <stdarg.h> shall not be used
 */
extern void use_double(double);
extern void use_uint32(int);


#include <stdarg.h>

static void h ( va_list ap )        //@violation DO_NOT_USE_STDARG_FEATURE
{
   double y;

   y = va_arg ( ap, double );   //@violation DO_NOT_USE_STDARG_FEATURE

   use_double ( y );
}


static void f ( int n, ... )
{
   int x;

   va_list ap;                     //@violation DO_NOT_USE_STDARG_FEATURE

   va_start ( ap, n );             //@violation DO_NOT_USE_STDARG_FEATURE
   x = va_arg ( ap, int );   //@violation DO_NOT_USE_STDARG_FEATURE
   use_uint32 ( x );

   h ( ap );

   /* undefined - ap is indeterminate because va_arg used in h ( ) */
   x = va_arg ( ap, int );   //@violation DO_NOT_USE_STDARG_FEATURE

   use_uint32 ( x );
   /* undefined - returns without using va_end ( ) */
}


void R_17_1 ( void )
{
   /* undefined - uint32_t:double type mismatch when f uses va_arg( ) */
   f ( 1, 2.0, 3.0 );
}

/* end of R_17_01.c */

