//@checker BEWARE_OF_COMPILER_OPTIMIZATIONS

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#ifdef _WIN32
#include <windows.h>
#endif


#pragma optimize("", off)
void getPassword2(int * test, int* test2)
{
	if(test)
	{
		//free(test);
		memset(test,0,sizeof(int));
	}
	
	if(test2)
	{
		//free(test2);
		memset(test2,0,sizeof(int));
	}
	
	
}
#pragma optimize("", on)