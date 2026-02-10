//@checker MACRO_IF_EXPRESSION_SHALL_EVAL_TO_BOOLEAN
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
 * R.20.8
 *
 * The controlling expression of a #if or #elif preprocessing directive shall 
 * evaluate to 0 or 1
 */




#define FALSE 0

#if FALSE                 /* Compliant     */
#endif

#if 10                    /* Non-compliant */ //@violation MACRO_IF_EXPRESSION_SHALL_EVAL_TO_BOOLEAN
#endif

#if !0
#endif

#if ! defined ( X )        /* Compliant    */
#endif

#define A 10
#define B 5

#if  A > B                 /* Compliant    */
#endif

void R_20_8 ( void )
{
  return;
}

/* end of R_20_08.c */
