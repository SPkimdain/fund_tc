//@checker DEFINE_INLINE_IN_HEADER_FILES

#include "8_1_2.h"


int TEST::getX() //@violation DEFINE_INLINE_IN_HEADER_FILES
{
	return this->x;
}

inline void foo() //@violation DEFINE_INLINE_IN_HEADER_FILES
{
	int x = 0;	
}

int bar( int x )
{
	return x + 10;
}

namespace
{
	//Allow. unnamed namespace.
	inline void foo2()
	{
		int x = 0;
		x++;
	}
}

namespace nsTest
{
	//Now Allow. named namespace.
	inline void foo3() //@violation DEFINE_INLINE_IN_HEADER_FILES
	{
		int x = 0;
		x++;
		x++;
	}
}


int main()
{
	return 1;
}
