// @checker IMPLICIT_WIDEN_CAST_COMPLEX_FLOAT_EXPR

typedef	float	float32_t;
typedef	double float64_t;
typedef	long double float128_t;

struct _my_struct{
	float32_t	foo;
};

typedef struct _my_struct my_struct;

float32_t	get_float32();

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

	f64r = my.foo + f32b;			//@violation IMPLICIT_WIDEN_CAST_COMPLEX_FLOAT_EXPR
	f64r = my_ptr->foo + f32b;	//@violation IMPLICIT_WIDEN_CAST_COMPLEX_FLOAT_EXPR
    f64r = f64r + (f32a + f32b);    //@violation IMPLICIT_WIDEN_CAST_COMPLEX_FLOAT_EXPR
	f64r = get_float32 ( ) + f32r; //@violation IMPLICIT_WIDEN_CAST_COMPLEX_FLOAT_EXPR
    f32r = f32a * f32b;
    f64r = f64r + f32r;
    f64r = f64r + ( (float64_t) f32a * f32b ); 
	f64r = f64r + f32r; 

}