// @checker PLAIN_CHAR_OPERATION

#define TEST_INT	100
#define TEST_CHAR		'M'

typedef char	char_t;
typedef unsigned char u_char_t;
typedef signed char s_char_t;

char test(){
	return 'P';
}

typedef struct _my_struct {
	char_t foo;
	int bar;
} my_struct;


void func(void) {
    char_t foo = 'K';
	char bar = 'a';
	u_char_t	foo2 = 111u;
	s_char_t	bar2 = 123;
	my_struct info;
	char_t foo_array[10];
	char bar_array[10][10];

	bar = 100 +bar_array[0][0];//@violation PLAIN_CHAR_OPERATION	
	bar = info.foo + 50; //@violation PLAIN_CHAR_OPERATION
	bar = 20 * foo_array[0] + 20;	//@violation PLAIN_CHAR_OPERATION	
	bar = info.foo;
	bar = foo_array[0];

	bar = test() - 50;//@violation PLAIN_CHAR_OPERATION
	bar = 1 + foo;//@violation PLAIN_CHAR_OPERATION
	bar = 100 - foo;//@violation PLAIN_CHAR_OPERATION
	bar = 100 + (char_t)(foo << 2) * 200;	//@violation PLAIN_CHAR_OPERATION
	foo--;//@violation PLAIN_CHAR_OPERATION
	foo++;	//@violation PLAIN_CHAR_OPERATION
	bar = foo / 2;//@violation PLAIN_CHAR_OPERATION
	bar = foo * 2;//@violation PLAIN_CHAR_OPERATION
	bar = bar2 - 20;
}
