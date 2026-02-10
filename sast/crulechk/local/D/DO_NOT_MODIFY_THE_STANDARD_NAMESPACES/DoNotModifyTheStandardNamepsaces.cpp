//@checker DO_NOT_MODIFY_THE_STANDARD_NAMESPACES
// #include <iostream>


namespace std {
int x; //@violation DO_NOT_MODIFY_THE_STANDARD_NAMESPACES

	int test( ) //@violation DO_NOT_MODIFY_THE_STANDARD_NAMESPACES
	{
		return 5;
	}
	  int f(short a) //@violation DO_NOT_MODIFY_THE_STANDARD_NAMESPACES
    {
    	// cout << a;
      return  a += a;
    }
    
}

using std::f;

int asdf_dntsn()
{
	return f(std::x);
}