//@checker DO_NOT_USE_IMPLICIT_DECLARED_FUNCTION

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
 * R.17.3
 *
 * A function shall not be declared implicitly
 */


//extern float64_t power (float d, int n);
/* 
 *  not visible at use
 */


extern int test (void);
void R_17_3 ( void )
{
   float sq1 = power ( 1, 2.0 );   //@violation DO_NOT_USE_IMPLICIT_DECLARED_FUNCTION

   int sq2 = test();
   
}

/* end of R_17_03.c */
