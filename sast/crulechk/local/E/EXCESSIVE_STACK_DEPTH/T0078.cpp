//@checker EXCESSIVE_STACK_DEPTH

//Base

void T0078func1()
{
	//Base01 - 가이드 예시
	char buf[65537]; //@violation EXCESSIVE_STACK_DEPTH	
}

//Complex

typedef struct _ComplexStruct
{
	int x;
	long y;
	float z;
} ComplexStruct;

void T0078func2()
{
	int x = 5;
	int bufxxx[3000] = {x + 1};
	int bufxx[3000] = {5};
	int bufx[3000] = {0, 1, 2, 3, 5};
	//Complex01 - 사이즈와의 곱이 65536이상	
	int buf[30000] = {0, x}; //@violation EXCESSIVE_STACK_DEPTH
}

void T0078func3()
{
	//Complex02 - 특정 자료형과 사이즈와의 곱이 65536 이상
	ComplexStruct cs[30000]; //@violation EXCESSIVE_STACK_DEPTH
}

void T0078func4()
{
	//Complex03 - 2차원 배열 크기의 곱이 65536 이상
	char buf[10][6560]; //@violation EXCESSIVE_STACK_DEPTH
}

void T0078func5()
{
	//Complex04 - 자료형 및 2차원 배열의 복합 구성 사이즈 곱이 65536 이상
	ComplexStruct cs[10][3000]; //@violation EXCESSIVE_STACK_DEPTH
}

//C++Support

class T0078A
{
public:
	//C++Support01 - 필드 선언의 크기가 65535 이상
	char buf[65537]; //@violation EXCESSIVE_STACK_DEPTH

	void mFunc1()
	{
		return;
	}
};

class T0078B
{
public:
	char x;
};

void T0078func6()
{
	//C++Support02 - 클래스 타입의 사이즈 곱이 65536 이상
	T0078B buf[65536]; //@violation EXCESSIVE_STACK_DEPTH	
}

template<typename T>
class T0078C
{
public:
	//C++Support08 - 81번 라인에 의해 int buf[30000];짜리 코드가 생성되므로 해당 위치에서 알람 발생
	T buf[30000]; //@violation EXCESSIVE_STACK_DEPTH
};

void T0078func7()
{
	//C++Support03 - 템플릿의 선언 시점에서 특정 내부 필드 사이즈 곱이 65535이상
	T0078C<int> t; //@violation EXCESSIVE_STACK_DEPTH
};

