// @checker MUST_HAVE_AN_IDENTIFIER

void var_func1(int var1, int, int var3);  // @violation MUST_HAVE_AN_IDENTIFIER
void var_func2(int, int); // @violation MUST_HAVE_AN_IDENTIFIER
void var_func3(int x, int y);

void var_func2(int a, int b)
{
	int c = a + b;
}

void var_func1(int var1, int var2, int var3)
{
	var1 = var2 + var3;
}

void var_func(int x, int y)
{
	int z = x - y;
}



int main()
{
	var_func1(1, 2, 3);	
}
