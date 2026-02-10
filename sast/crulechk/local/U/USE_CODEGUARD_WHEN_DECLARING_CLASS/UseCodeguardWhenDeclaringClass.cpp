//@checker USE_CODEGUARD_WHEN_DECLARING_CLASS
#include "UseCodeguardWhenDeclaringClass.hpp"
#include "UseCodeguardWhenDeclaringClass2.hpp"



int test ()
{
	UseCodeguardWhenDeclaringClass i;
	UseCodeguardWhenDeclaringClass2 i2;
	return i.i + i2.i;
}