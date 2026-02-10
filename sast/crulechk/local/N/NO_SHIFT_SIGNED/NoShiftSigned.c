// @checker NO_SHIFT_SIGNED

typedef signed int SINT_32;

struct tag_my_struct
{
	int bar;
};


void foo(void)
{
	SINT_32 a = 0;
	SINT_32 b = 1;
	struct tag_my_struct c;
	SINT_32 d[10] = {100,};
	short e = 10;
	long f = 11;
	char g = 3;
	unsigned int h = 100u;

	b = c.bar << 2;	//@violation NO_SHIFT_SIGNED
	a = d[0] >> 3;	//@violation NO_SHIFT_SIGNED

	b >>= 1;		//@violation NO_SHIFT_SIGNED
	a = b << 3;	//@violation NO_SHIFT_SIGNED

	a = e << 2; //@violation NO_SHIFT_SIGNED
	a = f >> 3; //@violation NO_SHIFT_SIGNED

	a = g >>7; //@violation NO_SHIFT_SIGNED

	a = h >> 2;	
}
