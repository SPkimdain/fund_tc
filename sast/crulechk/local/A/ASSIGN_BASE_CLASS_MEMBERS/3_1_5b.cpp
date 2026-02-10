//@checker ASSIGN_BASE_CLASS_MEMBERS

class NBase
{
};

class Base : public NBase 
{
public:
	Base& operator=(const Base& rhs)
	{
		bValue = rhs.bValue;

		return *this;
	}

private:
	int bValue;
};

/* 문제 없음1 */
class Derived1 : public Base
{
public:
	Derived1& operator=(const Derived1& rhs)
	{
		Base::operator =(rhs);
		dValue = rhs.dValue;

		return *this;
	}

private:
	int dValue;
};


/* Base의 operator=를 호출하지 않음. */
class Derived2 : public Base
{
public:
	Derived2& operator=(const Derived2& rhs) //@violation ASSIGN_BASE_CLASS_MEMBERS
	{
		dValue = rhs.dValue;
	}
private:
	int dValue;
};

/* AS test. */
class Deriveddd : public Base
{
public:
	Deriveddd& operator=(const Deriveddd& rhs)  { dValue = rhs.dValue; int a =5;}  //@violation ASSIGN_BASE_CLASS_MEMBERS

private:
	int dValue;
};



class Base2 //@b-violation ASSIGN_BASE_CLASS_MEMBERS
{
public:
	Base2& operator=(const Base2& rhs)
	{
		bValue2 = rhs.bValue2;
	}
private:
	int bValue2;
};

/* 다중상속이며 이중 하나를 호출하지 않음 */
class Derived3 : public Base, Base2
{
public:
	Derived3& operator=(const Derived3& rhs) //@violation ASSIGN_BASE_CLASS_MEMBERS
	{
		Base::operator =(rhs);
		dValue = rhs.dValue;

		return *this;
	}
private:
	int dValue;
};

/* 다중상속이며 둘다 호출하지 않음 */
class Derived4 : public Base, Base2
{
public:
	Derived4& operator=(const Derived4& rhs) //@violation ASSIGN_BASE_CLASS_MEMBERS
	{
		dValue4 = rhs.dValue4;

		return *this;
	}
private:
	int dValue4;
};

int main()
{
	Derived3 inst1, inst2;
	inst1 = inst2;

	return 0;
}
