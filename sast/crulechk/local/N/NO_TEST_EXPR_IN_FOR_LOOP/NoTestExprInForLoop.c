// @checker NO_TEST_EXPR_IN_FOR_LOOP

void NTESTEIFL_001_function(const char foo, const char bar)
{
	for(int i = 0; ; i++) //@violation NO_TEST_EXPR_IN_FOR_LOOP
	{
		/*......*/
	}

	for(int j = 0; j < 100; j++)
	{
		/*......*/
	}
}
