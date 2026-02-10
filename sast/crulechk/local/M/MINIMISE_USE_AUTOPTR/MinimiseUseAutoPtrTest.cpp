//@checker MINIMISE_USE_AUTOPTR

#include <stdio.h>
#include <memory>

using namespace std;

int foo( auto_ptr<int> a )
{
	return *a;
}

int bar( auto_ptr<int>& a )
{
	return *a;
}

int main()
{
	int* x = new int;
	int y = 10;
	auto_ptr<int> a( new int ); 
	auto_ptr<int> b(x);
	auto_ptr<int> c;
	
	//1.array type을 auto_ptr로 사용하는 경우
	auto_ptr<int> d( new int[10] ); //@violation MINIMISE_USE_AUTOPTR
	
	//2.동적할당이 아닌 변수로 auto_ptr을 생성
	auto_ptr<int> e( &y ); //@violation MINIMISE_USE_AUTOPTR

	//foo( ai ); // destructive copy
	*a = 10; // error a no longer exists


	//4.auto_ptr 객체를 다른 auto_ptr 객체로 Assignment 하는 경우
	c = b; //@violation MINIMISE_USE_AUTOPTR
	*c = 5;

	printf( "%d\n", *a );
	printf( "%d\n", *c );

	//3.auto_ptr 객체를 값에 의한 전달 인자로 사용하는 경우
	printf( "%d\n", foo( a ) ); //@violation MINIMISE_USE_AUTOPTR
	
	printf( "%d\n", bar( c ) );

	printf( "%d\n", *c );
}
