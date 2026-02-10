// @checker TAG_NAME_SHALL_BE_A_UNIQUE

void func()
{
	struct StructTest //@b-violation TAG_NAME_SHALL_BE_A_UNIQUE
	{
		int x;
		int y;
		int z;
	} instance1;

	struct StructTest instance2;
}


void func2()
{
	union StructTest //@violation TAG_NAME_SHALL_BE_A_UNIQUE
	{
		short a;
		short b;
	} instance3;

}

void func3()
{
	struct StructTest //@violation TAG_NAME_SHALL_BE_A_UNIQUE
	{
		char c;
		char d;
	} instance4;
}

void func4()
{
	enum StructTest //@violation TAG_NAME_SHALL_BE_A_UNIQUE
	{
		first,
		second
	} enumList;

	struct StructTest2 //@b-violation TAG_NAME_SHALL_BE_A_UNIQUE
	{
		int xx;
		int yy;
	};
}

void StructTest2() //@violation TAG_NAME_SHALL_BE_A_UNIQUE
{
	return;
}

int func5( int StructTest2 ) //@violation TAG_NAME_SHALL_BE_A_UNIQUE
{
StructTest: //@violation TAG_NAME_SHALL_BE_A_UNIQUE

	int StructTest = 10; //@violation TAG_NAME_SHALL_BE_A_UNIQUE

	union StructTest4 //@b-violation TAG_NAME_SHALL_BE_A_UNIQUE
	{
		short xxx;
		char yyy;
	} instance5;

	return 1;
}

void func6()
{
	typedef char StructTest4; //@violation TAG_NAME_SHALL_BE_A_UNIQUE

	struct StructTest3
	{
		int x;
		char StructTest2; //@violation TAG_NAME_SHALL_BE_A_UNIQUE
	};
}

void func7()
{
	enum EnumTest
	{
		melon,
		StructTest2 //@violation TAG_NAME_SHALL_BE_A_UNIQUE
	} enumList2;
}

int main()
{
	return 1;
}
