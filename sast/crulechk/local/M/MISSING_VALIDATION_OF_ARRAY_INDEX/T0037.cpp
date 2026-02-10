
//@checker MISSING_VALIDATION_OF_ARRAY_INDEX

#define CHECK_BOUNDARY_VALUE( index, boundary ) index < boundary

//Base

void func1( int index, int value )
{
	int arr[30];

	//Base01 - 가이드 예시
	arr[index] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
}

void func2( int index, int index2, int value, int& value2 )
{
	int arr[10];
	
	//Base02 - 가이드 예시2
	arr[index] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX

	//Base03 - 우측항
	value2 = arr[index2]; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
}


int func3( int arr[], int index, int index2, int value )
{
	//Base04 - 2번 사용(같은 수식, 다른 라인)
	return arr[index] + //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
		arr[index2]; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
}

void func4( int arr[][10], int index )
{
	//Base05 - 2차원 배열(앞부분)
	arr[index][0] = 10; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
	
	//Base06 - 2차원 배열(뒷부분)
	arr[0][index] = 10;
}


//Complex

void func5( int index, int index2, int value )
{
	int arr[5][10];

	//Complex01 - 이차원 배열에서 한 차원만 사이즈 검사(첫번째 차원)
	if( index < 5 )
	{
		arr[index][index2] = value;
	}

	//Complex02 - 이차원 배열에서 한 차원만 사이즈 검사(두번째 차원)
	if( index2 < 10 )
	{
		arr[index][index2] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
	}
}

int getSize( bool flag)
{
	//컴파일러 최적화 되지 않도록 복잡성 부여
	int x = 1;
	if( flag )
	{
		return x + 9;
	}
	else
	{
		return x + 5;
	}

}

void func6( int index, int value )
{
	int arr[10];
	//Complex03 - 검사에 사용되는 비교 수식값이 함수의 리턴값
	if( index < getSize( true ) )
	{
		arr[index] = value; //Checking False Alarm
	}
}

void func7( int index, int value )
{
	int arr[10];
	//Complex04 - 복잡한 수식( 괄호 + 우측 Operand 배치 )
	if( ( 1 + index ) < 11 )
	{
		arr[index] = value; //Checking False Alarm
	}
}

void func8( int index, int value )
{
	int arr[10];
	//Complex05 - 매크로
	if( CHECK_BOUNDARY_VALUE( index, 10 ) )
	{
		arr[index] = value; //Checking False Alarm
	}
}

void func14( int index, int value )
{
	int arr[10];
	//Complex06 - 범위를 벗어날 경우 리턴
	if( index >= 10 )
	{
		return;
	}

	arr[index] = value; //Checking False Alarm
}

void func15( int index, int value )
{
	int arr[10];
	//Complex07 - 검사를 하지만 아무것도 하지 않음
	if( index >= 10 )
	{
		int x = 0;
	}

	arr[index] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
}

//C++Support

namespace 
{
	void func9( int index, int value )
	{
		int arr[10];
		//C++Support01 - 네임스페이스 안 함수
		arr[index] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
	}
	
	namespace nested
	{
		void func10( int index, int value )
		{
			int arr[10];
			//C++Support02 - nested 네임스페이스 안 함수
			arr[index] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
		}
	}
}



class T0037A
{
public:
	void mfunc1( int index, int value )
	{
		int arr[10];
		//C++Support03 - 클래스 선언부
		arr[index] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
	}

	void mfunc2( int index, int value );
};

void T0037A::mfunc2(int index, int value)
{
	int arr[10];
	//C++Support04 - 클래스 정의부
	arr[index] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
}

void func13( int index, int value )
{
	int arr[10];

	try
	{
		//C++Support09 - try문
		arr[index] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX

		if( index >= 10 )
		{
			throw index;
		}

		//C++Support10 - try문으로 유효성 검증(범위를 벗어날경우 catch로)
		//arr[index] = value; //Checking False Alarm
	}
	catch( int exp )
	{
		int x = exp;
	}
}
