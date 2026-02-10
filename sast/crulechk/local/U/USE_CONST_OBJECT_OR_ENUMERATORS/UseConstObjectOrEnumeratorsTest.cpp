
//@checker USE_CONST_OBJECT_OR_ENUMERATORS

#define START 1 //@violation USE_CONST_OBJECT_OR_ENUMERATORS
#define RUNNING 2 //@violation USE_CONST_OBJECT_OR_ENUMERATORS
#define END 3 //@violation USE_CONST_OBJECT_OR_ENUMERATORS

#define FILE_NAME "Test" //@violation USE_CONST_OBJECT_OR_ENUMERATORS

#define TEST(x, y) if( ( x ) ) \
	y = y + 1


int main()
{
	int x = START;
	x = RUNNING;
	x = END;

	char *str = FILE_NAME;

	TEST( 10, x );
	return 1;
}
