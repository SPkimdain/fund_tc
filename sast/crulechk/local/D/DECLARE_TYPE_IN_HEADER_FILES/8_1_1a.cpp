//@checker DECLARE_TYPE_IN_HEADER_FILES

#include "8_1_1a.h"

enum level2 { low2, med2, high2 };  //@violation DECLARE_TYPE_IN_HEADER_FILES

int foo2( int );  //@violation DECLARE_TYPE_IN_HEADER_FILES

class Org2;  //@violation DECLARE_TYPE_IN_HEADER_FILES

struct Line2{ float dx; float dy; };  //@violation DECLARE_TYPE_IN_HEADER_FILES

const float s2 = 3.0E8;  //@violation DECLARE_TYPE_IN_HEADER_FILES


float f2 = 3.0E8;

int bar2( int ); //@violation DECLARE_TYPE_IN_HEADER_FILES

int bar2( int xx )
{
	int barx = 0;
	barx++;

	return barx;
}

int car( int xx )
{
	int carx = 0;
	carx++;

	return carx;
}

namespace 
{
	int x2 =  0;
}

namespace nsTest2 //@violation DECLARE_TYPE_IN_HEADER_FILES
{ 
	int x = 0;
	void foo()
	{
		int y = 0;
		y++;
	}
}

class Test2 //@violation DECLARE_TYPE_IN_HEADER_FILES
{
public:
	void mfunc() {}
	void mfunc2();
};

void Test2::mfunc2()
{
	int x = 0;
	x++;
}

int main()
{
}