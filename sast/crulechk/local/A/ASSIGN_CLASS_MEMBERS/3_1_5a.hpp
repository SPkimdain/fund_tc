//@checker ASSIGN_CLASS_MEMBERS 

extern char * strcpy ( char * destination, const char * source );

/* 문제 없는 클래스 */
class C1
{
public:
	C1& operator=(const C1& rhs)
	{
		value1 = rhs.value1;
		value2 = rhs.value2;
		strcpy(value3, rhs.value3);

		return *this;
	}

private:
	int value1;
	double value2;
	char value3[256];
};

/* 일부 변수를 대입하지 않음 */
class C2 
{
public:
	C2& operator=(const C2& rhs);

private:
	int value1;
	double value2; //@b-violation ASSIGN_CLASS_MEMBERS
	char value3[256]; //@b-violation ASSIGN_CLASS_MEMBERS
};

