
int foo(void)
{
	int r;
	r = func(0);
	return r;
}

extern int bar(int value);

int foo1(void)
{
	int c;
	c = bar(0);
	return c;
}