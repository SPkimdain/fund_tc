//@checker DO_NOT_USE_DIGRAPH

#include <stdio.h>

int DNUDIGRAPH_001_function()
{
	int x = 0;
	if( x ) <% //@violation DO_NOT_USE_DIGRAPH
		x++;
	}

	printf( "<:" );	//@violation DO_NOT_USE_DIGRAPH
}
