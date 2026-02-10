//@checker DO_NOT_OVERRIDE_ADDRESSOF
class A
{
	public :
	A* operator& ( ); //@violation DO_NOT_OVERRIDE_ADDRESSOF
	
};

class B
{
	
};

void f2(A& a)
{
	&a;
	B b;
	&b;
	
}