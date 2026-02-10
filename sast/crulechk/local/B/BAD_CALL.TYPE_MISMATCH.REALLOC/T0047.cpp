//@checker BAD_CALL.TYPE_MISMATCH.REALLOC
#include <stdlib.h>
#include <memory.h>

typedef struct _exam1
{
	int a;
	double b;
	char *c;
} Exam1;

typedef struct _exam2
{
	char *d;
	double e;
	int f;
} Exam2;

Exam1 *ep1;
Exam2 *ep2;

void T0047func1()
{
	ep1 = ( Exam1* )malloc( sizeof( Exam1 ) );

	//Base01 - 가이드 예시
	ep2 = ( Exam2* )realloc( ep1, sizeof( Exam2 ) ); //@violation BAD_CALL.TYPE_MISMATCH.REALLOC

	free(ep1);
	free(ep2);
}
