/*
 * Release: 2014-01-13
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */
//@checker EMPTY_ARRAY_SIZE
/*
 * R.9.5
 *
 * Where designated initialisers are used to initialize an array object the 
 * size of the array shall be specified explicitly
 */



void R_9_5 ( void )
{
   int a1[ ]    = { [0] = 1 };    /* Non-compliant - probably unintentional to have single element */ //@violation EMPTY_ARRAY_SIZE 
   int a2[ 10 ] = { [0] = 1 };    /* Compliant                                                     */

   
}

/* end of R_09_05.c */
