// @checker IMPLICIT_CONVERSION_FLOAT_PARAM

typedef	float	float32_t;
typedef	double float64_t;
typedef	long double float128_t;

void calc_float64(float64_t value)
{
	value = value+1.0f;
}
void calc_float32(float32_t value);

struct _my_struct{
	float32_t	foo;
};

typedef struct _my_struct my_struct;

void func()
{
	float32_t f32a, f32b, f32r;
	float64_t f64a, f64b, f64r;
	my_struct	my;
	my_struct *my_ptr;
	float32_t my_array[10];
	float32_t my_array2[10][10];
	float32_t *f32p;

	calc_float64(my.foo);	//@violation IMPLICIT_CONVERSION_FLOAT_PARAM
	calc_float64(my_ptr->foo);	//@violation IMPLICIT_CONVERSION_FLOAT_PARAM
	calc_float64(my_array[0]);	//@violation IMPLICIT_CONVERSION_FLOAT_PARAM
	calc_float64(my_array2[0][0]);	//@violation IMPLICIT_CONVERSION_FLOAT_PARAM
	calc_float64(*f32p);	//@violation IMPLICIT_CONVERSION_FLOAT_PARAM
	calc_float64(f32a);	//@violation IMPLICIT_CONVERSION_FLOAT_PARAM
	calc_float32(f64a);	
	calc_float64((float64_t)f32a);
	calc_float64(f64a);
	
	
}