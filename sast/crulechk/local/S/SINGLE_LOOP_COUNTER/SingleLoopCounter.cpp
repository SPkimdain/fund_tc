//@checker SINGLE_LOOP_COUNTER
void SLCountrer()
{
	int y = 0;
	int a= 0 ;
	for (int x= 0 ; x < y ; x++, y++) //@violation SINGLE_LOOP_COUNTER
	{
		a++;
	}
}
