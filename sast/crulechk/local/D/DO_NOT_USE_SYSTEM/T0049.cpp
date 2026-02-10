//@checker DO_NOT_USE_SYSTEM

#define SYSTEM_CMD( x ) system( x )

//Base
extern int system (const char* command);

void T0049func1()
{
	//Base01 - 가이드 예시
	system("ls -al"); //@violation DO_NOT_USE_SYSTEM
}

//Complex

void assert( int x )
{
	if( x )
	{
		x++;
	}
	else
	{
		x--;
	}
}

void T0049func2()
{
	int x = 0;

	//Complex01 - 함수 파라메터 내에서의 system 호출
	assert( system( "ls -al" ) ); //@violation DO_NOT_USE_SYSTEM

	//Complex02 - 조건절 내에서의 system 호출
	if( system( "ls -al" ) == -1 ) //@violation DO_NOT_USE_SYSTEM
	{
		x++;
	}

	//Complex03 - 매크로 사용
	SYSTEM_CMD( "ls -al " ); //@violation DO_NOT_USE_SYSTEM
}
