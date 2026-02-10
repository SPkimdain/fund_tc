//@checker USE_CONST_GLOBAL_AND_STATIC

static int global; // @violation USE_CONST_GLOBAL_AND_STATIC
int globalx = 0; // @violation USE_CONST_GLOBAL_AND_STATIC
int* globaly = 0; // @violation USE_CONST_GLOBAL_AND_STATIC
const int globalz = 5;
volatile int globalj = 10; // @violation USE_CONST_GLOBAL_AND_STATIC
const int* globalk = &globalz;
volatile int* globall = &globalj; // @violation USE_CONST_GLOBAL_AND_STATIC
const volatile int* globalm = &globalz;

void foo()
{
	static int fj; // @violation USE_CONST_GLOBAL_AND_STATIC
	static int fx = 5; // @violation USE_CONST_GLOBAL_AND_STATIC
	static int* fy = &fx; // @violation USE_CONST_GLOBAL_AND_STATIC
	int fz = 7;
	const static int fk = 10;
}

int main()
{
	return 1;
}

