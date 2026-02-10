// @checker DO_NOT_USE_C_STYLE_ALLOCATION

typedef long size_t;
extern void* malloc (size_t size);
extern void free (void* ptr);

int DNUCSTYLEALLOC_001_function()
{
	int *t1;
	int *t2;

	t1 = ( int * ) malloc( sizeof( int ) ); // @violation DO_NOT_USE_C_STYLE_ALLOCATION
	t2 = ( int * ) malloc( sizeof( int ) ); // @violation DO_NOT_USE_C_STYLE_ALLOCATION

	free( t2 );  // @violation DO_NOT_USE_C_STYLE_ALLOCATION
	free( t1 );  // @violation DO_NOT_USE_C_STYLE_ALLOCATION

}
