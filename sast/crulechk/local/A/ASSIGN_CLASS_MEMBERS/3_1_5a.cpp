//@checker ASSIGN_CLASS_MEMBERS 

#include "3_1_5a.hpp"

enum EnumTest
{
	ET_A,
	ET_B,
	ET_C
};

C2& C2::operator=(const C2& rhs) //@violation ASSIGN_CLASS_MEMBERS
{
	value1 = rhs.value1;

	return *this;
}


/* 일부 변수에 값을 대입하지 않음. */
class C3
{
public:
	C3& operator=(const C3& rhs) //@violation ASSIGN_CLASS_MEMBERS
	{
		/* value1이 사용되었지만 대입 연산자의 좌측항이 아님. */
		value2 = rhs.value1 + rhs.value2;
		strcpy(value3, rhs.value3);

		return *this;
	}

private:
	int value1; //@b-violation ASSIGN_CLASS_MEMBERS
	double value2; 
	char value3[256];
	EnumTest et;
	unsigned short* ptr;
};


int main()
{

	return 0;
}

