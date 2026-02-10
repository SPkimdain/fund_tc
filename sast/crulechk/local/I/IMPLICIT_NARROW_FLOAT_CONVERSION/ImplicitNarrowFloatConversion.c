// @checker IMPLICIT_NARROW_FLOAT_CONVERSION

typedef	float	float32_t;
typedef	double float64_t;
typedef	long double float128_t;

float64_t	get_float64();
float32_t	get_float32();

struct _my_struct{
	float32_t	foo;
};

typedef struct _my_struct my_struct;

void func()
{
	float32_t f32a, f32b, f32r;
	float64_t f64a, f64b, f64r;
	float128_t	f128r;
	my_struct	my;
	my_struct *my_ptr;
	float32_t my_array[10];
	float32_t my_array2[10][10];
	float32_t *f32p;

	my_ptr->foo = f64a + f64b;	//@violation IMPLICIT_NARROW_FLOAT_CONVERSION
	*f32p = f64a + f64b;	//@violation IMPLICIT_NARROW_FLOAT_CONVERSION
	my_array2[0][0] = f64a + f64b;	//@violation IMPLICIT_NARROW_FLOAT_CONVERSION
	my_array[0] = f64a + f64b;	//@violation IMPLICIT_NARROW_FLOAT_CONVERSION
	
	my.foo = f64a + f64b;	//@violation IMPLICIT_NARROW_FLOAT_CONVERSION

	f32r = get_float64 ( );         //@violation IMPLICIT_NARROW_FLOAT_CONVERSION
	f32r = get_float32();
	f32r = f64a + f64b;		//@violation IMPLICIT_NARROW_FLOAT_CONVERSION

	f32r = (float32_t)get_float64();
	f64r = f32a + f32b;
	
}