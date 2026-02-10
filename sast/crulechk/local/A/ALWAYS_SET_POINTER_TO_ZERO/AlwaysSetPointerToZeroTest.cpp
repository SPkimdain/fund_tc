//@checker ALWAYS_SET_POINTER_TO_ZERO
#include <stdlib.h>

void foo()
{
	int *px = ( int * )malloc( sizeof( int ) );
	int *py = ( int * )malloc( sizeof( int ) );
	
	free( px ); //@violation ALWAYS_SET_POINTER_TO_ZERO

	free( py );
	py = 0;

	int **p2d = new int*[10];
	for( int i = 0; i < 10; i++ )
	{
		p2d[i] = new int[3];
	}
	
	p2d[0][2] = 5;

	for( int i = 0; i< 10; i++ )
	{
		//mangling *p2d;
		delete[] p2d[i]; //@violation ALWAYS_SET_POINTER_TO_ZERO
	}

	delete[] p2d;
	p2d = 0;

	char *pch = new char;
	
	delete pch; //@violation ALWAYS_SET_POINTER_TO_ZERO
}


class TEST
{
public:
	void mfunc()
	{
		field = new int[10];

		//Field
		delete[] field; //@violation ALWAYS_SET_POINTER_TO_ZERO
		
	}
	int *field;
};

int main()
{
	return 1;
}
