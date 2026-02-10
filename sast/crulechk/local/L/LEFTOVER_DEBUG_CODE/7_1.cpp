//@checker LEFTOVER_DEBUG_CODE
#define NULL 0
extern int printf ( const char * format, ... );
extern int strcmp ( const char * str1, const char * str2 );
extern const char * strstr ( const char * str1, const char * str2 );
extern int puts ( const char * str );

int func( char* input, int y )
{

	if( strcmp( input, "debug" ) == 0 ) //조건절에서 상수값에 debug가 들어가는 경우 해당 조건절 이하 문장을 debug block으로 판별
		printf("Use printing function.\n"); //@violation LEFTOVER_DEBUG_CODE

	if( strstr( input, "debug" ) != NULL ) //조건절에서 상수값에 debug가 들어가는 경우 해당 조건절 이하 블럭을 debug block으로 판별
	{
		printf( "Use printing function.\n"); //@violation LEFTOVER_DEBUG_CODE
	}

	int x = 1;

	if( x == 1 )
	{
		printf( "It's not debug block\n");

		x = x + y;
		if( x > 5 )
		{
			printf( "It's not debug block\n");
			
			if( strcmp( input, "debug" ) == 0 )
			{
				printf( "Use printing function.\n"); //@violation LEFTOVER_DEBUG_CODE

				if( x == 10 )
				{
					printf( "Use printing function.\n"); //@violation LEFTOVER_DEBUG_CODE
				}
			}

			printf( "It's not debug block\n");
		}
	}

	printf( "It's not debug block\n");

	return 1;
}

int main()
{
	func("debug", 10 );

	printf("Debug Info...\n"); //@violation LEFTOVER_DEBUG_CODE

	puts("Debug Message\n"); //@violation LEFTOVER_DEBUG_CODE
}
