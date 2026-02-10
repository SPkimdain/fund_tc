
//@checker FUNCTION_WITHOUT_DEFINITION




//C++Support

class T0040A
{
public:
	//C++Support01 - 클래스에서 메소드를 선언만 함
	void mFunc1( int x ); //@violation FUNCTION_WITHOUT_DEFINITION
};


//Base

//Base01 - 가이드 예시
int func1( int x ); //@violation FUNCTION_WITHOUT_DEFINITION