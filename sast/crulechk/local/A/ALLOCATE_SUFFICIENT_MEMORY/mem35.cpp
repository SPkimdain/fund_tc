//@checker ALLOCATE_SUFFICIENT_MEMORY
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int globalX = 10;

void func( int size, int k )
{
	long *x = 0;

	if( k == 10 )
	{
		if( size < 10000 && size >= 0 )
		{
			/* sizeof 문제 없음 */
			x = (long*)malloc( sizeof(long) );			
			free(x);
			/* sizeof 문제 없음 및 size 바운드리가 잘 되어 있음*/
			x = (long*)malloc( size * sizeof(long) );
			free(x);
			/* sizeof 다른 타입 */
			x = (long*)malloc( sizeof(int) ); //@violation ALLOCATE_SUFFICIENT_MEMORY
			free(x);
		}

		/* size 바운더리 체크가 안되어 있음 */
		x = (long*)malloc( size * sizeof(long) ); //@violation ALLOCATE_SUFFICIENT_MEMORY
		free(x);

		if( size < 1000 )
		{
			if( size >= 0 )
			{
				x = (long*)malloc( size * sizeof(long) );
			}
			else if( k > 10 )
			{
				return;
			}
			else
			{
				return;
			}
		}
	}

	/* 상수 값 사용, 문제 없음 */
	x = (long*)malloc( 10 * sizeof(long) ); 
	free(x);

	/* 외부 값(혹은 필드) 사용, 무시함 */
	x = (long*)malloc( globalX * sizeof(long) ); 
	free(x);

	if( k == 12 )
	{
		unsigned int uSize = 10;
		/* unsigned의 경우 0 체크 불필요 */
		if( uSize <= 10000 )
		{
			x = (long*)malloc( uSize * sizeof(long) );
			free(x);
		}

		/* 위쪽 바운더리 없을 경우 알람 */
		if( uSize >= 0 )
		{
			x = (long*)malloc( uSize * sizeof(long) ); //@violation ALLOCATE_SUFFICIENT_MEMORY
			free(x);
		}
	}
}

int main()
{
	
	func(10, 5);

	return 0;
}

