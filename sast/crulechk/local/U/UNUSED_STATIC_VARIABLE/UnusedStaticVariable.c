//@checker UNUSED_STATIC_VARIABLE

static int a;
static int b;
static int c;
static int d;  //@violation UNUSED_STATIC_VARIABLE

void func()
{
	a = 1;
	b++;
	c = c + 3;
}