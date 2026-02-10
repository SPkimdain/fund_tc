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


/* AS test. */
class Deriveddd : public Base
{
public:
	Deriveddd& operator=(const Deriveddd& rhs)  { dValue = rhs.dValue; int a =5;}  //@violation ASSIGN_BASE_CLASS_MEMBERS

private:
	int dValue;
};
