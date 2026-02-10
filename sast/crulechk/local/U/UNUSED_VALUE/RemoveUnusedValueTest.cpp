//@checker UNUSED_VALUE


int foo()
{
	int a = 2; //@violation UNUSED_VALUE
	int b;
	int c;
	int d;  //@violation UNUSED_VALUE
	int e;  //@violation UNUSED_VALUE

	a = 5;   

	b = 3;

	c = 3;
	d = 4;
	e = 5;
	
	return 3+b+4+c+2;
}

void foo2(int b)
{
	int a; //@violation UNUSED_VALUE   
	if (b > 2)
	{
		a = 5;
	}
	else
	{
		a = 6;
	}
}
