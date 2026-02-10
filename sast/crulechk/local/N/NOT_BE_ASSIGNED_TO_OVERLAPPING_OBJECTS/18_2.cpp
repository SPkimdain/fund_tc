// @checker NOT_BE_ASSIGNED_TO_OVERLAPPING_OBJECTS

typedef long size_t;
extern void * memcpy ( void * destination, const void * source, size_t num );
extern int printf ( const char * format, ... );
extern char * strncpy ( char * destination, const char * source, size_t num );
extern char * strcpy ( char * destination, const char * source );
extern char * strcat ( char * destination, const char * source );
extern void * memmove ( void * destination, const void * source, size_t num );

using namespace std;

typedef struct _Obj
{
	char* getStrP()
	{
		return str;
	}

	int x;
	int y;
	char z;
	char str[128];
	char str2[128];
} Obj;

typedef struct _NestedObj
{
	char* getStr( int x )
	{
		if( x == 10 )
		{
			return "true";
		}
		else
		{
			return "false";
		}
	}

	Obj obj;
} NestedObj;

int NBATOO_func1()
{
	Obj a = {0};
	Obj b = {0};

	b.x = 5;
	b.y = 10;

	char str[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	char str2[128] = { 0 };
	memcpy( &str[10], &str[13], 6 ); // @violation NOT_BE_ASSIGNED_TO_OVERLAPPING_OBJECTS

	printf( "%s\n", str );

	strncpy( &str[5], &str2[3], 3 );

	printf( "%s\n", str );

	strncpy( str, str, 10 ); // @violation NOT_BE_ASSIGNED_TO_OVERLAPPING_OBJECTS

	printf( "%s\n", str );

	strcpy( str, str ); // @violation NOT_BE_ASSIGNED_TO_OVERLAPPING_OBJECTS

	printf( "%s\n", str );

	strcat( str, str ); // @violation NOT_BE_ASSIGNED_TO_OVERLAPPING_OBJECTS

	printf( "%s\n", str );

	memmove( &a.str[5], &a.str[3], 6 ); // @violation NOT_BE_ASSIGNED_TO_OVERLAPPING_OBJECTS

	memmove( &a.str[5], &b.str[3], 6 );

	memmove( &a.str[5], &a.str2[3], 6 );

	NestedObj c = { 0 };

	memmove( &c.obj.str[5], &c.obj.str[3], 6 ); // @violation NOT_BE_ASSIGNED_TO_OVERLAPPING_OBJECTS

	strcpy( &c.obj.str[10], c.getStr( 10 ) );

	const char* text = "Template";
	strcpy( str, text );

	strcpy( a.getStrP(), a.getStrP() ); // @violation NOT_BE_ASSIGNED_TO_OVERLAPPING_OBJECTS

	strcpy( b.getStrP(), a.getStrP() );

	printf( "%s\n", str );

	return 1;
}


