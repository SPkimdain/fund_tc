#ifndef _CUSTOM_TYPEDEF_H_
#define _CUSTOM_TYPEDEF_H_


typedef	signed   int bool_t; 
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

typedef	double float64_t;
typedef	long double float128_t;

struct _my_int_struct{
	int8_t		foo8;
	uint8_t	foo8u;
	int16_t		foo16;
	uint16_t		foo16u;
	int32_t		foo32;
	uint32_t		foo32u;
	int64_t		foo64;
	uint64_t		foo64u;
};

typedef struct _my_int_struct my_int_struct;

int8_t *get_int8_ptr ( void );
int8_t get_int8 ( void );
int16_t get_int16 ( void );
int32_t get_int32 ( void );
int64_t get_int64 ( void );
uint8_t get_uint8 ( void );
uint16_t get_uint16 ( void );
uint32_t get_uint32 ( void );
uint64_t get_uint64 ( void );

float64_t	get_float64();
float32_t	get_float32();

void use_uint8(uint8_t	value);
void use_uint16(uint16_t	value);
void use_uint32(uint32_t	value);
void use_uint64(uint64_t	value);
void use_int8(int8_t	value);
void use_int16(int16_t	value);
void use_int32(int32_t	value);
void use_int64(int64_t	value);

#endif
