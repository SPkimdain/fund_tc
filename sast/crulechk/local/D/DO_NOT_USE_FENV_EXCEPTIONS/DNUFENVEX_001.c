//@checker DO_NOT_USE_FENV_EXCEPTIONS
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
 * R.21.12
 *
 * The exception handling features of <fenv.h> should not be used
 */

#define FE_DIVBYZERO 0
#define FE_OVERFLOW 1

extern float get_float32();
extern int feclearexcept(int);
extern int fetestexcept(int);



static void DNUFENVEX_001_function1 ( float x, float y )
{
   float z;

   ( void ) feclearexcept ( FE_DIVBYZERO ); //@violation DO_NOT_USE_FENV_EXCEPTIONS

   z = x / y;

   if ( fetestexcept ( FE_DIVBYZERO ) != 0 ) //@violation DO_NOT_USE_FENV_EXCEPTIONS
   {
   }
   else
   {
#pragma STDC FENV_ACCESS on
       z = x * y;
   }

   if ( z > x )
   {
#pragma STDC FENV_ACCESS off
      if ( fetestexcept ( FE_OVERFLOW ) != 0 ) //@violation DO_NOT_USE_FENV_EXCEPTIONS
      {
      }
   }

}

void DNUFENVEX_001_function2 ( void )
{
   float x = get_float32 ( );
   float y = get_float32 ( );

   DNUFENVEX_001_function1(x, y);
}

/* end of R_21_12.c */

