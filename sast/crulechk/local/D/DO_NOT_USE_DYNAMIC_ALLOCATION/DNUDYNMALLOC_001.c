// @checker DO_NOT_USE_DYNAMIC_ALLOCATION

extern void* malloc (int size);
extern void free (void* ptr);

void DNUDYNMALLOC_001_function()
{
	int *t1;
	int *t2;

	t1 = ( int * ) malloc( sizeof( int ) ); // @violation DO_NOT_USE_DYNAMIC_ALLOCATION

	t2 = ( int * ) malloc( sizeof( int ) ); // @violation DO_NOT_USE_DYNAMIC_ALLOCATION

	free( t2 ); // @violation DO_NOT_USE_DYNAMIC_ALLOCATION
	free( t1 ); // @violation DO_NOT_USE_DYNAMIC_ALLOCATION
}
