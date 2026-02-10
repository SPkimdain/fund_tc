// @checker BAD_WHITESPACE.ACCESSING
#define TEST b ->f2 = 2

typedef struct {
    int f1;
    int f2;
} A;


void bad_whitespace_accessing() {
    int array[10];
    A a;
    A *b;

    array[0] = 1;
    array [1] = 2;     // @violation BAD_WHITESPACE.ACCESSING
    a.f1 = 1;
    a .f2 = 2;         // @violation BAD_WHITESPACE.ACCESSING
    b->f1 = 1;
    b ->f2 = 2;        // @violation BAD_WHITESPACE.ACCESSING
	TEST;
}
