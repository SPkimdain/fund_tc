//@checker INCLUDE_STDLIB_WITH_BRACKETS
#include "stdio.h"	//@violation	INCLUDE_STDLIB_WITH_BRACKETS
#include <string.h> //OK
#include <stdio.h> //OK


void IncludeStdLibWithBrackets()
{
	int x = 0;
}
