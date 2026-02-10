//@checker RETURN_PARAM_ADDR
class A
{
public :
	void f();
};

A& foo(A a)
{
	return a;	//@violation RETURN_PARAM_ADDR
}