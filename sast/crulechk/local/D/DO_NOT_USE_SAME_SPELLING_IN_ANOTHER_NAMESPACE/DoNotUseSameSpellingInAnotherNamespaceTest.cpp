//@checker DO_NOT_USE_SAME_SPELLING_IN_ANOTHER_NAMESPACE

void func()
{
	struct structTest //@b-violation DO_NOT_USE_SAME_SPELLING_IN_ANOTHER_NAMESPACE
	{
		short a;
		short b;
	};
}

void func2()
{
	struct structTest
	{
		int x; //Ignore
		int y;
	};
}

void structTest() //@violation DO_NOT_USE_SAME_SPELLING_IN_ANOTHER_NAMESPACE
{
	int x = 0; //Ignore
	enum EnumTest
	{
		first,
		structTest //@violation DO_NOT_USE_SAME_SPELLING_IN_ANOTHER_NAMESPACE
	} et;
	return;
}

void func3( char structTest ) //@violation DO_NOT_USE_SAME_SPELLING_IN_ANOTHER_NAMESPACE
{
labelStr: //@b-violation DO_NOT_USE_SAME_SPELLING_IN_ANOTHER_NAMESPACE
	return;
}

void func4()
{
	int labelStr = 5; //@violation DO_NOT_USE_SAME_SPELLING_IN_ANOTHER_NAMESPACE
	int structTest = 10; //@violation DO_NOT_USE_SAME_SPELLING_IN_ANOTHER_NAMESPACE
structTest: //@violation DO_NOT_USE_SAME_SPELLING_IN_ANOTHER_NAMESPACE
	return;
}

void func5( char labelStr ) //@violation DO_NOT_USE_SAME_SPELLING_IN_ANOTHER_NAMESPACE
{
	return;
}

int main()
{
	typedef char structTest; //@violation DO_NOT_USE_SAME_SPELLING_IN_ANOTHER_NAMESPACE

	return 1;
}

