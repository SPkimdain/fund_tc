// @checker DO_NOT_USE_DEF_WITHIN_A_BLOCK

#ifndef TEST
#define TEST 1

void main()
{
	int x = 0;
	if( x == 1 )
	{
#define TEST2 1 // @violation	DO_NOT_USE_DEF_WITHIN_A_BLOCK
	}
	else
	{
#undef TEST2 // @violation	DO_NOT_USE_DEF_WITHIN_A_BLOCK
	}
}

#endif //TEST
