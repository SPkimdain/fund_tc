// @checker PLACE_PLAIN_CHAR
#define TEST_INT	100
#define TEST_CHAR		'M'
typedef char	char_t;
extern int printf ( const char * format, ... );

void func(const char foo, char_t bar) {
    
	switch(foo)	//@b-violation PLACE_PLAIN_CHAR
	{
	case 'a': case 'b': case 'c':
		printf("asdf");
		break;
	case 111:	//@violation PLACE_PLAIN_CHAR
		printf("asdffff");
		break;
	default:
		printf("kgkgkgkg");
		break;
	}

	switch(bar)	//@b-violation PLACE_PLAIN_CHAR
	{
	case 'a':
		printf("asdf");
		break;
	case TEST_INT:	//@violation PLACE_PLAIN_CHAR
		printf("asdffff");
		break;
	default:
		printf("kgkgkgkg");
		break;
	}
}
