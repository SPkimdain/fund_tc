//@checker DECLARE_CONTROL_VARIABLES_WITHIN_FOR

extern int printf ( const char * format, ... );

int main()
{
	int x = 0;
	for(int i = 0; i < 10; i++)
	{
		x += 5;
	}

	int j = 0;
	for(j = 0; j < 10; j++) // @violation DECLARE_CONTROL_VARIABLES_WITHIN_FOR
	{
		x += 5;
	}
		
	for(int i = 0, k = 0; i < 10 || k < 10; i++, k++ )
	{
		x += 2;
	}

	printf("%d\n",x);
}
