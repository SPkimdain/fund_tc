//@checker DO_NOT_USE_SIZEOF_ON_PTR

typedef int INTTYPE;
typedef INTTYPE *INTTYPE_PTR;

//Base

void T0057func1()
{
	int *arr;
	int x = 0;
	//Base01 - 가이드 예시
	if( sizeof( arr ) < 10 ) //@violation DO_NOT_USE_SIZEOF_ON_PTR
	{
		x++;
	}
}

//Complex

void T0057func2()
{
	int **arr;
	int x = 0;
	int size = 0;
	//Complex01 - 이중포인터에 1번만 역참조 한 경우
	if( sizeof( *arr ) < 10 ) //@violation DO_NOT_USE_SIZEOF_ON_PTR
	{
		x++;
	}

	//Complex02 - 레퍼런스에 대해 sizeof 한 경우
	if( sizeof( &x ) < 10 ) //@violation DO_NOT_USE_SIZEOF_ON_PTR
	{
		x++;
	}

	//Complex03 - 복합절에서 sizeof 사용
	size = 5 + x + ( sizeof( arr ) + 10 ); //@violation DO_NOT_USE_SIZEOF_ON_PTR

	INTTYPE_PTR z;
	//Complex04 - typedef 포인터 타입 이용
	if( sizeof( z ) == 10 ) //@violation DO_NOT_USE_SIZEOF_ON_PTR
	{
		x++;
	}

	//Complex05 - 정적 로컬변수 배열의 경우(해당 경우를 sizeof 한 경우 정상적인 값이 나옴)
	char* arr2[32];
	if( sizeof( arr2 ) == 128 ) //Checking False Alarm
	{
		x++;
	}
}
