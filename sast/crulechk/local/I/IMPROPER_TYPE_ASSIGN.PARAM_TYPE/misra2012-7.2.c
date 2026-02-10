//@checker IMPROPER_TYPE_ASSIGN.PARAM_TYPE

typedef	char		char_t;
typedef	signed char		int8_t;
typedef	unsigned char	uint8_t;
typedef	short	int16_t;
typedef	unsigned short uint16_t;
typedef	int		int32_t;
typedef	unsigned int uint32_t;
typedef	long		int64_t;
typedef	unsigned long uint64_t;
typedef	float	float32_t;



extern void use_char ( char_t use_char_param );
extern void use_int8 ( int8_t use_int8_param );
extern void use_int16 ( int16_t use_int16_param );
extern void use_int32 ( int32_t use_int32_param );
extern void use_int64 ( int64_t use_int64_param );

extern void use_uint8 ( uint8_t use_uint8_param );
extern void use_uint16 ( uint16_t use_uint16_param );
extern void use_uint32 ( uint32_t use_uint32_param );
extern void use_uint64 ( uint64_t use_uint64_param );


void test()
{
	use_int64  ( 2147483647 );          /* long constant */
	use_uint32 ( 0x7fffffffU );          /* unsigned int constant -  Non-compliant */
	use_uint32 ( 0x7fffffff );          /* unsigned int constant -  Non-compliant */ //@violation IMPROPER_TYPE_ASSIGN.PARAM_TYPE
	
		 use_int32  ( 2147483647 );          /* int constant */
       use_int32  ( 0x7FFFFFFF );          /* int constant */
       
       use_uint32 ( 2147483648U );         /* unsigned int constant */
       
       use_uint32 ( 0x80000000U );         /* unsigned int constant */

	   
}