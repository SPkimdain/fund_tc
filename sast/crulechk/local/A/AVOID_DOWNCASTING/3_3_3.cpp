//@checker AVOID_DOWNCASTING

#include "3_3_3.h"

void AVDDWNCAST_001_function()
{ 
	int y = 0;
    A* a = new B; 
	B* bb;
	((B*)a)->foo(); //@violation AVOID_DOWNCASTING
	((B*)(a))->foo(); //@violation AVOID_DOWNCASTING
	(((B*)(a)))->foo(); //@violation AVOID_DOWNCASTING
	static_cast< B* >( a )->foo(); //@violation AVOID_DOWNCASTING
    a->bar(); // prefer 

	B* b = new B;
	((A*)b)->bar(); // prefer
	(((A*)b))->bar(); // prefer
	static_cast< A* >( b )->bar(); //prefer
	
	if( (B*)a == 0 ) //@violation AVOID_DOWNCASTING
	{
		y++;
	}

	static_cast< B*>( a )->car( ((B*)a)->x ); //@violation AVOID_DOWNCASTING

	delete b;
	delete a;
} 
