//@checker SIDE_EFFECT.DESIGNATED_INIT

struct mystruct{
	int a;
	int b;
	int c;
	int d;
};

void g(int *p)
{
	struct mystruct s1 = {.a =100, .b = *p++, .c = 5, .d = -1 };// @violation SIDE_EFFECT.DESIGNATED_INIT
	struct mystruct s2 = {.a =100, .b = 10, .a = 5, .d = -1 };	
}

void f(int *p)
{
	int a1[5] = {[0] = -5, [1] = *p++, [2] = -3, [3] = -2, [4] = -1};	// @violation SIDE_EFFECT.DESIGNATED_INIT
	int a2[5] = {[0] = -5, [1] = -4, [2] = -3, [2] = -2, [4] = -1};	

}
/*
EDG error
void f1(int a)
{
	int a1[a] = {[0] = -5, [1] = -4, [2] = -3, [3] = -2, [4] = -1};	// skip check because size of a is unknown
	int a2[a] = {[0] = -5, [1] = -4, [2] = -3, [2] = -2, [4] = -1};	// skip check because size of a is unknown

}*/
