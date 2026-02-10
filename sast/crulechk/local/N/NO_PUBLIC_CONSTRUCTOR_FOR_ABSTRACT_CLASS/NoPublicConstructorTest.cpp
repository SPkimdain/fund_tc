//@checker NO_PUBLIC_CONSTRUCTOR_FOR_ABSTRACT_CLASS
class AbstractClass
{
public:
	AbstractClass() {} //@violation NO_PUBLIC_CONSTRUCTOR_FOR_ABSTRACT_CLASS
	virtual void func() = 0;
};

class AbstractClass2
{
private:
	AbstractClass2() {}
	virtual void func2() = 0;
};


class NonAbstractClass
{
public:
	NonAbstractClass() {}
};
