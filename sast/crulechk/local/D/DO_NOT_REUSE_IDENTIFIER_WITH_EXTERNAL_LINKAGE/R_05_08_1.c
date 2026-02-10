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
 * R.5.8
 *
 * Identifiers that define objects or functions with external linkage shall be 
 * unique
 */
//@checker DO_NOT_REUSE_IDENTIFIER_WITH_EXTERNAL_LINKAGE





extern int count8;           /* "count8" has external linkage - Note: breaks R.8.4 */

/* Note: foo8 has intentionally no separate declaration, breaks R.8.4 */
void foo8 ( void )        /* "foo8" has external linkage   */
{
   int index;         /* compliant - "index" has no linkage       */
	int count8 = 1; //@violation DO_NOT_REUSE_IDENTIFIER_WITH_EXTERNAL_LINKAGE
   
  //index = get_int16 ( );
  // use_int16 ( index );
  // use_int32 ( count8 );
}

void R_5_8 ( void )
{
  // count8 = get_int32 ( );
  // foo8 ( );
  return;
  // R_5_8_2 ( );
}


/* End of R_05_08_01.c */


