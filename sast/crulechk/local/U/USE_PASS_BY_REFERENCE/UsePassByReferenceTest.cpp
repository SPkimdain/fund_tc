//@checker USE_PASS_BY_REFERENCE

#include <vector>

using std::vector;

typedef struct _strctTest
{
	int x;
	int y;
} StrctTest;

class Test
{
public:
	Test() {}
	void mfunc() const
	{
		int x = 0;
		x++;
	}
private:
	int field1;
	float field2;
};

void foo( StrctTest arg ) //@violation USE_PASS_BY_REFERENCE
{
	arg.x = 10;
	arg.y = 20;
}

void foo2( StrctTest& arg )
{
	arg.x = 10;
	arg.y = 20;
}

void foo3( StrctTest* arg )
{
	arg->x = 10;
	arg->y = 20;
}

void bar( Test inst ) //@violation USE_PASS_BY_REFERENCE
{
	inst.mfunc();
}

void bar2( const Test& inst )
{
	inst.mfunc();
}

void bar3( int x, int y, Test* inst )
{
	inst->mfunc();
}

void car( vector<int> intArr ) //@violation USE_PASS_BY_REFERENCE
{
	intArr.clear();
}

void car2( const vector<int>& intArr )
{
	int x = 0;
}

void car3( vector<int>& intArr )
{
	intArr.clear();
}

void car4( vector<int>* intArr )
{
	intArr->clear();
}

int main()
{
	return 1;
}
