//@checker MISSING.DESIGNATED_INIT

struct mystruct{
	int a;
	int b;
	int c;
	int d;
};

void g(void)
{
	struct mystruct s1 = {.a =100, .b = 10, .c = 5, .d = -1 };
	struct mystruct s2 = {.a =100, .b = 10, .a = 5, .d = -1 };	// @violation MISSING.DESIGNATED_INIT
}

void f(void)
{
	int a1[5] = {[0] = -5, [1] = -4, [2] = -3, [3] = -2, [4] = -1};	// compliant
	int a2[5] = {[0] = -5, [1] = -4, [2] = -3, [2] = -2, [4] = -1};	// @violation MISSING.DESIGNATED_INIT

}
/*
EDG error
void f1(int a)
{
	int a1[a] = {[0] = -5, [1] = -4, [2] = -3, [3] = -2, [4] = -1};	// skip check because size of a is unknown
	int a2[a] = {[0] = -5, [1] = -4, [2] = -3, [2] = -2, [4] = -1};	// skip check because size of a is unknown

}*/