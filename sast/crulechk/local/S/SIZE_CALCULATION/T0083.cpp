//@checker SIZE_CALCULATION

typedef long size_t;
extern void* malloc (size_t size);
extern void free (void*);

void T0083func1()
{
	int length = 10;
	double *p;

	//Base01 - 가이드 예시
	p = ( double * )malloc( length * sizeof( int ) ); //@violation SIZE_CALCULATION

	free( p );
	
}

//Complex

void T0083func2()
{
	int length = 20;
	double **p;
	//Complex01 - 이중 포인터
	p = ( double ** )malloc( length * sizeof( double* ) ); //Checking False Alarm
	
	free( p );

}
