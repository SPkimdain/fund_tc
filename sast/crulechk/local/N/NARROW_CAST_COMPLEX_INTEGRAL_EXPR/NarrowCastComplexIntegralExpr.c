// @checker NARROW_CAST_COMPLEX_INTEGRAL_EXPR

#include "custom_typedef.h"

void func()
{
	int8_t	s8r;
	uint8_t u8r;
	int16_t s16a, s16b, s16r;
	uint16_t u16r;
	int32_t s32a, s32b, s32r;
	uint32_t u32r;
	int64_t s64a, s64b, s64r;
	uint64_t u64r;
	
	int i = 0;

	 int16_t    array [ 10 ];
	 int16_t *  ps16 = 0;

    s8r  = ( int8_t )  ( s32a + s32b );       /* Compliant      */
    s16r = ( int16_t ) ( s32a + s32b );       /* Compliant      */
	s32r = ( int32_t ) ( s16a + s16b);			//@violation NARROW_CAST_COMPLEX_INTEGRAL_EXPR
    s32r = ( int32_t ) ( s32a + s32b );       /* Compliant - Redundant cast */
    s64r = ( int64_t ) ( s32a + s32b );       //@violation NARROW_CAST_COMPLEX_INTEGRAL_EXPR

	s64r = ( int64_t ) s32r; 

	s64r = ( int64_t ) s32a + s32b;           /* Compliant - A2 - 64 bit
                                               * summation                    */

	u32r = ( uint32_t ) ( u16r >> 2 );        //@violation NARROW_CAST_COMPLEX_INTEGRAL_EXPR
	u16r = ( uint16_t ) ( ++u8r );            //@violation NARROW_CAST_COMPLEX_INTEGRAL_EXPR 
    s32r = ( int32_t )  ( *ps16 + 1 );        //@violation NARROW_CAST_COMPLEX_INTEGRAL_EXPR
    s16r = ( int16_t )  ( get_int8 ( ) + 1 ); //@violation NARROW_CAST_COMPLEX_INTEGRAL_EXPR
    

	s32r = ( int32_t )array [ i + 1 ];        /* Compliant      */

    s32r = ( int32_t ) ( *get_int8_ptr( ) );  /* Compliant      */


}