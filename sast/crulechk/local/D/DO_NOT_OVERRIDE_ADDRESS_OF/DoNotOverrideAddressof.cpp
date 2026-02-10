//@checker DO_NOT_OVERRIDE_ADDRESSOF
#include "DoNotOverrideAddressof.h"
void f (A& a)
{
	 & a; //
}

