//@checker DYNAMIC_TYPE_IN_CTOR_OR_DTOR
#include <typeinfo>
class B1
{
	public:
	B1()
	{
		typeid (B1); 
	}
};

class B2
{
	public:
	virtual ~B2();
	virtual void foo ();
	B2 ()
	{
		typeid (B2); //@violation DYNAMIC_TYPE_IN_CTOR_OR_DTOR
		B2::foo();
		dynamic_cast<B2*> ( this ); //@violation DYNAMIC_TYPE_IN_CTOR_OR_DTOR
		
		
		
	}
	
};

void DYNAMIC_TYPE_IN_CTOR_OR_DTOR_test()
{
	B1 b1();
	B2 b2();
	
}