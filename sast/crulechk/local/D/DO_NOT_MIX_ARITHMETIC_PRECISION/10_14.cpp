//@checker DO_NOT_MIX_ARITHMETIC_PRECISION


#include "10_14.h"


long long foo( int x, long long y )
{
	return x + y; //@violation DO_NOT_MIX_ARITHMETIC_PRECISION
}

void DoNotMixArthmetic::checkFunc()
{
	//Int & Long * long long
	int intX = 10;
	long longX = 100L;
	int y = 0;
	long z = 10;
	long long longlongX = 100LL;
	long long lz = 10LL;

	y = intX + longX; 

	y = intX + 10;

	y = intX + 10LL;  //@violation DO_NOT_MIX_ARITHMETIC_PRECISION

	z = longX + 10L;

	//long long형이 int형으로 assign 됨
	y = longlongX + 10LL; //@violation DO_NOT_MIX_ARITHMETIC_PRECISION

	//int형이 long long형으로 assign 됨	
	longlongX = intX + 10; //@violation DO_NOT_MIX_ARITHMETIC_PRECISION

	y = ( 10 + 5 / 2 + ( longlongX + 3LL ) );  //@violation DO_NOT_MIX_ARITHMETIC_PRECISION

	z = longlongX + longX; //@violation DO_NOT_MIX_ARITHMETIC_PRECISION
		
	//Float & Double & long double
	//'F' & 'f' suffix is float type.

	float floatX = 10.F;
	double doubleX = 5.5;
	long double longdoubleX = 5.5L;
	float fy = 0.F;
	double dy = 0.0;
	long double ldy = 0.0L;
	
	fy = floatX + longdoubleX; //@violation DO_NOT_MIX_ARITHMETIC_PRECISION
	
	fy = floatX + 5.F;

	fy = floatX + intX; //@violation DO_NOT_MIX_ARITHMETIC_PRECISION

	dy = doubleX + 5.0;

	//long double형이 float형으로 assign 됨
	fy = longdoubleX + 5.0; //@violation DO_NOT_MIX_ARITHMETIC_PRECISION

	//float형이 long double형으로 assign 됨
	ldy = floatX + 5.F; //@violation DO_NOT_MIX_ARITHMETIC_PRECISION

	fy = 5.0 + 10.5F / 2.0F + ( floatX + 3.0L ); //@violation DO_NOT_MIX_ARITHMETIC_PRECISION

	fy = longdoubleX / 2.0; //@violation DO_NOT_MIX_ARITHMETIC_PRECISION

	//Func, condition, function parameter
	if( floatX > intX ) //@violation DO_NOT_MIX_ARITHMETIC_PRECISION
	{
		y++;
	}

	lz = foo( 10 + intX, 10LL + longlongX );

	lz = foo( 10LL + intX, 10 + longlongX ); //@violation DO_NOT_MIX_ARITHMETIC_PRECISION

	//Checking between return type and assign right hand side type.
	y = foo( 10 + intX, 10LL + longlongX ); //@violation DO_NOT_MIX_ARITHMETIC_PRECISION

	fy = intX + this->getFloat(); //@violation DO_NOT_MIX_ARITHMETIC_PRECISION

	y = intX + (int)longlongX; //Check false alarm.
}

int main()
{
	return 1;
}
