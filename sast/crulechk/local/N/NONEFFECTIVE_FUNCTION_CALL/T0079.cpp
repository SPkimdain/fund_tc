//@checker NONEFFECTIVE_FUNCTION_CALL
typedef long size_t;

extern void * memset ( void * ptr, int value, size_t num );
extern void * memcpy ( void * destination, const void * source, size_t num );
extern wchar_t* wmemcpy (wchar_t* destination, const wchar_t* source, size_t num);
extern int snprintf ( char * s, size_t n, const char * format, ... );

void T0079func1()
{
	char buf[10];
	char dest[10];
	char src[10];
	wchar_t wdest[10];
	wchar_t wsrc[10];

	//Base01 - 가이드 예시
	memset( buf, 10, '\0' ); //@violation NONEFFECTIVE_FUNCTION_CALL

	//Base02 - 가이드 예시(memcpy)
	memcpy( dest, src, 0 ); //@violation NONEFFECTIVE_FUNCTION_CALL

	//Base03 - 가이드 예시(wmemcpy)
	wmemcpy( wdest, wsrc, 0 ); //@violation NONEFFECTIVE_FUNCTION_CALL

	//Base04 - 가이드 예시(snprintf)
	snprintf( buf, 0, "%s%s", dest, src ); //@violation NONEFFECTIVE_FUNCTION_CALL

}
