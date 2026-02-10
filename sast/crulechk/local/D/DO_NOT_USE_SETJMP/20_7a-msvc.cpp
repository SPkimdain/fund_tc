//@checker DO_NOT_USE_SETJMP

#include <setjmp.h>

jmp_buf mainTask, childTask;

void child (void) 
{

	for (;;) 
	{
		setjmp(childTask); // @violation DO_NOT_USE_SETJMP

		if (!setjmp(childTask)) // @violation DO_NOT_USE_SETJMP
		{                      
			longjmp(mainTask, 1);
		}
	}

}

int main()
{
	child();
	return 1;
}
