//@checker DO_NOT_USE_UNUSED_TYPE_GLOBAL

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
 * R.2.3
 *
 * A project should not contain unused type declarations
 */




static int unusedtype ( void )
{
   typedef int local_Type;   /* Non-compliant */ //@violation DO_NOT_USE_UNUSED_TYPE_GLOBAL

   return 67;
}

void R_2_3 ( void )
{
   
}

/* end of R_02_03.c */
