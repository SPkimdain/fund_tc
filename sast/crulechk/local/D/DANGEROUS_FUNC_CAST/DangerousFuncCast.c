//@checker DANGEROUS_FUNC_CAST

void foo1()
{
	return 'b';
}

void foo2()
{
	int(*fp_foo2)();
	fp_foo2 = (int(*)())foo1; //@violation DANGEROUS_FUNC_CAST
}


