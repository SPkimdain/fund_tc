// @checker NO_INC_EXPR_IN_FOR_LOOP

#define TEST_INT	100
#define TEST_CHAR		'M'

void NINCEIFL_001_function(const char foo, const char bar)
{
	for(int i = 0; i < 100; ) //@violation NO_INC_EXPR_IN_FOR_LOOP
	{
		/*......*/
	}

	for(int j = 0; j < 100; j++)
	{
		/*......*/
	}
}
