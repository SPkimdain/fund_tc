//@checker AVOID_USING_STATIC_KEYWORD

static int sVal = 10;
int nVal2 = 10;

static void foo() // @violation AVOID_USING_STATIC_KEYWORD
{
	int x = 0;
}

void bar()
{
	int x = 0;
}

namespace test
{
	static int sVal2 = 10; // @violation AVOID_USING_STATIC_KEYWORD
	int nVal2 = 10;

	static void foo2() // @violation AVOID_USING_STATIC_KEYWORD
	{
		int x = 0;
	}
	
	void bar2()
	{
		int x = 0;
	}
};

namespace
{
	int sVal3;
	void foo3()
	{
		int x = 0;
	}
};

int main()
{
	return 1;
}