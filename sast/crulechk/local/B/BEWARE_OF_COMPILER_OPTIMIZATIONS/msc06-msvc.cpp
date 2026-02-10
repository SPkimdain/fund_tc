//@checker BEWARE_OF_COMPILER_OPTIMIZATIONS

typedef long size_t;
extern void * memset ( void * ptr, int value, size_t num );
extern int printf ( const char * format, ... );
#ifdef _WIN32
#define ZeroMemory(D,L) memset((D),0,(L))
#endif

bool GetPassword(char* pwd, size_t size)
{
	if( size == 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}


void getPassword(void)
{
	char pwd[64];
	char pwd2[64];
	char pwd3[64];

	
	if (GetPassword(pwd, sizeof(pwd))) 
	{
		/* Checking of password, secure operations, etc. */
	}
	
	/* 최적화 가능성 있음 */
	memset(pwd, 0, sizeof(pwd)); //@violation BEWARE_OF_COMPILER_OPTIMIZATIONS

	if (GetPassword(pwd2, sizeof(pwd2))) 
	{
		/* Checking of password, secure operations, etc. */
	}
	
	/* memset이후 사용함 */
	memset(pwd2, 0, sizeof(pwd2));

	printf("%s\n", pwd2); //여기서 사용

	
	if (GetPassword(pwd3, sizeof(pwd3))) 
	{
		/* Checking of password, secure operations, etc. */
	}

#ifdef _WIN32
	ZeroMemory(pwd3, sizeof(pwd3)); //@violation BEWARE_OF_COMPILER_OPTIMIZATIONS
#endif

}

#pragma optimize("", off)
void getPassword2()
{
	char pwd4[64];
	if (GetPassword(pwd4, sizeof(pwd4))) 
	{
		/* Checking of password, secure operations, etc. */
	}
	
	/* optimize 안쪽에 있어서 괜찮음 */
	memset(pwd4, 0, sizeof(pwd4));
}
#pragma optimize("", on)


int main()
{
	getPassword();
	getPassword2();

	return 0;
}


