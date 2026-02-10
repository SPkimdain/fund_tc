// @checker DO_NOT_USE_NON_STANDARD_CHARACTERS

#include "!@#abcd.h" // @violation DO_NOT_USE_NON_STANDARD_CHARACTERS
#include <stdio.h>



void main()
{
	printf("한글");
}
