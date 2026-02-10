// @checker BAD_SUFFIX_FOR_LONG_VALUE

void func()
{
	unsigned long x = 50u;
	long y = 0x1000l;	//@violation	BAD_SUFFIX_FOR_LONG_VALUE
	long y1 = 1000000l;	//@violation	BAD_SUFFIX_FOR_LONG_VALUE
	x  = x + 50000l;		//@violation	BAD_SUFFIX_FOR_LONG_VALUE
	x = y + 1 + 0xAAAAl;	//@violation	BAD_SUFFIX_FOR_LONG_VALUE
	x = y * 20 + 0xAAAAAlU;	//@violation	BAD_SUFFIX_FOR_LONG_VALUE
}
