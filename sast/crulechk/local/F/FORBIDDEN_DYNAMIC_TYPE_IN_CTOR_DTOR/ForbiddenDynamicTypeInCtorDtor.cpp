//@checker FORBIDDEN_DYNAMIC_TYPE_IN_CTOR_DTOR
#include <typeinfo>
class A{
public:
	void f();
	virtual ~A();
	virtual void foo();
	A()
	{
		typeid(A);	//@violation FORBIDDEN_DYNAMIC_TYPE_IN_CTOR_DTOR
		int a = (int)1.0f;
		dynamic_cast<A*> (this);	//@violation FORBIDDEN_DYNAMIC_TYPE_IN_CTOR_DTOR
	}
};