// @checker SPECIFY_LENGTH_TYPEDEF

typedef	signed char		int8_t;
typedef	unsigned char	uint8_t;
typedef   signed int          int32_t;
typedef	unsigned long       uint64_t;
typedef	float		float32_t;
typedef	double	float64_t;
typedef	int	my_int_t;		// @violation SPECIFY_LENGTH_TYPEDEF
typedef	short my_s_int_t;		// @violation SPECIFY_LENGTH_TYPEDEF
typedef	unsigned short	my_us_int_t;	// @violation SPECIFY_LENGTH_TYPEDEF
typedef	unsigned int my_u_int_t;	// @violation SPECIFY_LENGTH_TYPEDEF
typedef	float		my_float_t;	// @violation SPECIFY_LENGTH_TYPEDEF
typedef	enum { FALSE = 0, TRUE  = 1}			BOOL;
typedef	int		boolean;
typedef	char        char_t;


void func()
{
	char_t	a;
	my_float_t		b;
}
