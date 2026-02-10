//@checker DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM

#define CHECK_SIZE( Y ) sizeof( Y )
typedef unsigned int size_t;

//Base

void func1( int arr[] )
{
	int x = 0;
	size_t size;
	
	//Base01 - 가이드 예시
	int i;
	for( i = 0; i< sizeof( arr ) / sizeof( arr[0] ); i++ ) //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM
	{
		x++;
	}

	//Base02 - 배열 전체 sizeof( 01의 분리 테스트 )
	size = sizeof( arr ); //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM

	//Base03 - 배열 요소 sizeof( 01의 분리 테스트 )
	size = sizeof( arr[0] ); //Checking False Alarm
}


//Complex

void func2( int arr[], int arr2[][10] )
{
	int x = 0;
	size_t size;

	//Complex01 - 이중 배열
	size = sizeof( arr2 ); //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM

	//Complex02 - 논리연산 후위항에서 사용
	if( x == 1 && sizeof( arr2 ) > 10 ) //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM
	{
		x++;
	}

	//Complex03 - 복합수식절
	size = 3 + 5 + ( x - 2 / ( sizeof( arr ) ) ); //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM

	//Complex04 - 매크로 이용
	size = CHECK_SIZE( 5 );

}

//C++Support


namespace 
{
	int x = 0;
	size_t size;

	void func2( int arr[] )
	{
		//C++Support01 - 네임스페이스 안 함수
		size = sizeof( arr ); //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM
	}
	
	namespace nested
	{
		void func3( int arr[] )
		{
			//C++Support02 - nested 네임스페이스 안 함수
			size = sizeof( arr ); //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM
		}
	}
}



class T0043A
{
public:
	int x;
	size_t size;

	void mfunc1( int arr[] )
	{
		//C++Support03 - 클래스 선언부
		size = sizeof( arr ); //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM
	}

	void mfunc2( int arr[] );
};

void T0043A::mfunc2( int arr[] )
{
	//C++Support04 - 클래스 정의부
	size = sizeof( arr ); //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM
}

