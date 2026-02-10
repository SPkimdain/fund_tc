// @checker BAD_CAST_COMPLEX_EXPR

typedef	signed char		int8_t;
typedef	unsigned char	uint8_t;
typedef	short	int16_t;
typedef	unsigned short uint16_t;
typedef	int		int32_t;
typedef	unsigned int uint32_t;
typedef	long		int64_t;
typedef	unsigned long uint64_t;
typedef	float	float32_t;
typedef	double float64_t;
typedef	long double float128_t;

uint16_t get_uint8 ( void );

void func()
{
	int8_t	s8r;
	uint8_t u8r;
	int16_t s16a, s16b, s16r;
	uint16_t u16a, u16b, u16r;
	int32_t s32a, s32b, s32r;
	uint32_t u32a, u32b, u32r;
	int64_t s64a, s64b, s64r;
	uint64_t u64a, u64b, u64r;
	
	float32_t f32a, f32b, f32r;
	float64_t f64a, f64b, f64r;
	float128_t	f128r;

	uint16_t *  ps16 = 0;

	u8r  = ( uint8_t )  ( s16a + s16b );      //@violation BAD_CAST_COMPLEX_EXPR
    u16r = ( uint16_t ) ( s32a + s32b );      //@violation BAD_CAST_COMPLEX_EXPR
    u32r = ( uint32_t ) ( s32a + s32b );      //@violation BAD_CAST_COMPLEX_EXPR
    u64r = ( uint64_t ) ( s32a + s32b );      //@violation BAD_CAST_COMPLEX_EXPR

	s8r  = ( int8_t )  ( u64a + u64b );      //@violation BAD_CAST_COMPLEX_EXPR
    s16r = ( int16_t ) ( u32a + u32b );      //@violation BAD_CAST_COMPLEX_EXPR
    s32r = ( int32_t ) ( u16a + u16b );      //@violation BAD_CAST_COMPLEX_EXPR
    s64r = ( int64_t ) ( u32a + u32b );      //@violation BAD_CAST_COMPLEX_EXPR


    s8r  = ( int8_t )  ( s32a + s32b );       /* Compliant      */
    s16r = ( int16_t ) ( s32a + s32b );       /* Compliant      */
    s32r = ( int32_t ) ( s32a + s32b );       /* Compliant - Redundant cast */
	
	s32r = ( int32_t ) ( u16r >> 2 );        //@violation BAD_CAST_COMPLEX_EXPR
	s16r = ( int16_t ) ( ++u8r );            //@violation BAD_CAST_COMPLEX_EXPR 
    s32r = ( int32_t )  ( *ps16 + 1 );        //@violation BAD_CAST_COMPLEX_EXPR
    s16r = ( int16_t )  ( get_uint8 ( ) + 1 ); //@violation BAD_CAST_COMPLEX_EXPR

	f32r =  ( float32_t )  ( s32a + s32b );   //@violation BAD_CAST_COMPLEX_EXPR
    f64r =  ( float64_t )  ( s32a + s32b );   //@violation BAD_CAST_COMPLEX_EXPR
    f128r = ( float128_t ) ( s32a + s32b );   //@violation BAD_CAST_COMPLEX_EXPR

}