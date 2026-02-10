//@checker AVOID_CASTING_TO_VIRTUAL_CLASS


#include "3_3_4.h"

A* foo() 
{ 
    B* b = new B; 
	C c;
	A* a = 0;
	a = dynamic_cast< A* >( b ); // prefer
	a = static_cast< A* >( &c ); // prefer
    return static_cast< A* >( b ); //@violation AVOID_CASTING_TO_VIRTUAL_CLASS
	// avoid. casting to virtual base 

} 

int main()
{
	A* a = foo();
	B b;
	a = static_cast< A* >( &b ); //@violation AVOID_CASTING_TO_VIRTUAL_CLASS
	
	return 0;
}

