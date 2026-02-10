// @checker AVOID_BITWISE_ON_SAME_DATA

void func()
{
	unsigned int x = 50;
	x += (x << 2) + 1;		//@violation	AVOID_BITWISE_ON_SAME_DATA
	x >>= 2;	//@violation	AVOID_BITWISE_ON_SAME_DATA
}
