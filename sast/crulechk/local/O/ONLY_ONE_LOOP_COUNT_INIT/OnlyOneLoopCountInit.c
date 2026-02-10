// @checker ONLY_ONE_LOOP_COUNT_INIT

void func(void)
{
	int k = 0;
	int r = 0;
	int i,y,j;

	for(i = 0,  y = 0; i < 100; i++, k++) //@violation ONLY_ONE_LOOP_COUNT_INIT
	{
		/*......*/
	}

	for(r = 0, k = 0; k < 100; r++)	//@violation ONLY_ONE_LOOP_COUNT_INIT
	{
		/*......*/
	}



	for(j = 0; j < 100; k++)
	{
		/*......*/
	}

	for(k = 0; k < 100; k++)
	{
		/*......*/
	}
}
