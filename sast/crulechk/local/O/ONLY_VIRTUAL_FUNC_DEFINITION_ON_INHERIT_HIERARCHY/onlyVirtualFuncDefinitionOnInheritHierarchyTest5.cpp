//@checker ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY


//TC5////////////////////////
class A
{

public:
	virtual void f1() = 0;
	virtual void f2() = 0;
	virtual void f3() {}
	virtual void f4() = 0;

	virtual ~A();
};


void A::f1()
{

}

void A::f4()
{

}


class B : public A
{
public:
	virtual void f2() {}
	virtual void f3() {}       //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
	virtual void f4() = 0;
	virtual ~B();
};

void B::f4()
{

}


class C : public A
{
public:
	virtual void f1() {}
	virtual void f2() {}   //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
	virtual void f4() {}
};


class D : public C, B
{
public:
	virtual void f1() {}   //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
	virtual ~D();
};


