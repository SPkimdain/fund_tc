//@checker NULL_SHALL_BE_POINTER_CONSTANT

#include <stdio.h>


void g ( int *p )
{
	if ( p == NULL )
	{
		return;
	}
	return;
}