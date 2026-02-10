//@checker WRONG_PREPROCESSING_TOKEN
#define AAA 2
int foo_wpt(void)
{
	int x = 0 ;
#ifndef AAA
	x = 1;
#else1 //@violation WRONG_PREPROCESSING_TOKEN
	x = AAA;
#endif
	return x;
}