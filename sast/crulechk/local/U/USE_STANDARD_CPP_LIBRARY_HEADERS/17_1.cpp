//@checker USE_STANDARD_CPP_LIBRARY_HEADERS

#include "17_1a.h"

void foo()
{
	return;
}

#include "17_1b.h"

#include <wchar.h> //@violation USE_STANDARD_CPP_LIBRARY_HEADERS

int main()
{

	return 1;
}
