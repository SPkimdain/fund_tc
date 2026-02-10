// @checker DO_NOT_INC_ITER_WITH_VALUE_GREATER_THAN_ONE

void dniiwvgto_test()
{
	int i,j,t;
	for(t = 0; t < 100; t++)
	{
	}
	
	for(i = 0; i < 100; i=i+2) //@violation DO_NOT_INC_ITER_WITH_VALUE_GREATER_THAN_ONE
	{
		/*......*/
	}

	for(j = 0; i < 100; j+=2) //@violation DO_NOT_INC_ITER_WITH_VALUE_GREATER_THAN_ONE
	{
		/*......*/
	}
	
}
