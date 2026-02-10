// @checker TOO_LONG_IDENTIFIER

#define abcdefghijklmnopqrstuvwxyz12345ab	10	//@violation TOO_LONG_IDENTIFIER

typedef struct _abcdefghijklmnopqrstuvwxyz01234567890123	//@violation TOO_LONG_IDENTIFIER
{
	int abcdefghijklmnopqrstuvwxyz01234567890123;	//@violation TOO_LONG_IDENTIFIER
	int foo;
}MyStruct;

typedef union {
	int aaaa;
	short abcdefghijklmnopqrstuvwxyz01234567890123;//@violation TOO_LONG_IDENTIFIER
}uni_test;

typedef uni_test union_abcdefghijklmnopqrstuvwxyz01234567890123;	//@violation TOO_LONG_IDENTIFIER

extern int g_test_extern1;
extern int g_text_extern_abcdefghijklmnopqrstuvwxyz; // @violation TOO_LONG_IDENTIFIER

void func(void) {
    int abcdefghijklmnopqrstuvwxyz01234 = abcdefghijklmnopqrstuvwxyz12345ab; 
	int abcdefghijklmnopqrstuvwxyz0123456 = 0; // @violation TOO_LONG_IDENTIFIER
	int abcdefghijklmnopqrstuvwxyz01234abcdef = 0;	// @violation TOO_LONG_IDENTIFIER

	int abcdefghijklmnopqrstuvwxyz12345ab_aaa = 0;// @violation TOO_LONG_IDENTIFIER
	int bbb = abcdefghijklmnopqrstuvwxyz12345ab;
	abcdefghijklmnopqrstuvwxyz0123456 = 111;
	

}
