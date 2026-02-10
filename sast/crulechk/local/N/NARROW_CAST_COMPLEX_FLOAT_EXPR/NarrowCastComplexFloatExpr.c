// @checker NARROW_CAST_COMPLEX_FLOAT_EXPR

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

void NCCFE_001_function()
{
	int8_t	s8r;
	uint8_t u8r;
	int16_t s16r;
	uint16_t u16r;
	int32_t s32r;
	uint32_t u32r;
	int64_t s64r;
	uint64_t u64r;
	
	float32_t f32a, f32b, f32r;
	float64_t f64a, f64b, f64r;
	float128_t	f128r;

	f128r = ( float128_t ) ( f64a + f64b );  //@violation NARROW_CAST_COMPLEX_FLOAT_EXPR

  f32r = ( float32_t ) ( f64a + f64b );    /* Compliant */
  f64r = ( float64_t ) ( f64a + f64b );    /* Compliant - Redundant Cast */

	f32r = (float32_t)(f64a + f64b);
	f64r = (float64_t)(f32a + f32b);	//@violation	NARROW_CAST_COMPLEX_FLOAT_EXPR	

}
