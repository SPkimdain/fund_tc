// @checker ONLY_LOOP_COUNT_INC_DEC
extern int printf ( const char * format, ... );

void func(void)
{
	int k = 0;
	int r = 10;
	int i,j;
	for ( k = 0; k < r; k = k + 1 ) 
	{
	}

	
	for(k=0, r=0; k < r; k ++, r--)
	{
	}


	for(k = 0; k < 100; r++)	//@violation ONLY_LOOP_COUNT_INC_DEC
	{
		/*......*/
	}

	for(k = 0; k < 100; printf("%d\n", k))	//@violation ONLY_LOOP_COUNT_INC_DEC
	{
		/*......*/
	}


	for( i = 0; i < 100; i++, k++) //@violation ONLY_LOOP_COUNT_INC_DEC
	{
		/*......*/
	}

	for( j = 0; j < 100; k++)//@violation ONLY_LOOP_COUNT_INC_DEC
	{
		/*......*/
	}



	for(k = 0; k < 100; k++)
	{
		/*......*/
	}
}
