//@checker ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY




//TC8//////////////////////// 
class A
{

public:
	virtual void f1() {} 
	virtual void f1(int m) {}
};



class B : public A
{
public:
	virtual void f1(int m) {}     //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
	virtual void f1(char n) {}
	virtual void f1(int a, char b) {}
};




