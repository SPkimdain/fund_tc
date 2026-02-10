//@checker BAD_CALL.INCORRECT_SIZEOF.MEMCPY

extern void * memcpy ( void * destination, const void * source, int num );
//Base

void T0063func1( int x )
{
	char a[100];
	char b[100];
	char *ref = a;

	//Base01 - 가이드 예시
	memcpy( a, b, sizeof( ref ) ); //@violation BAD_CALL.INCORRECT_SIZEOF.MEMCPY
	

	//Base02 - 가이드 예시
	memcpy( a, b, sizeof( 10 * x ) ); //@violation BAD_CALL.INCORRECT_SIZEOF.MEMCPY

}

//Complex

void T0063func2()
{
	char a[100];
	char b[100];
	char *ref = a;
	

	//Complex01 - 괄호절 사용
	memcpy( a, b, sizeof( ( ( a ) ) ) ); //Checking False Alarm
}
