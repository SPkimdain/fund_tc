//@checker CATCH_EXCPETIONS_IN_HIERACHICAL_ORDER

// classes used for exception handling
class B { };
class D: public B { };
// Using the classes from above ...

void test_CEHO()
{
	try
	{
	  // ...
	}
	catch ( B &b )
	{
	  // ...
	}
	catch ( D &d ) // Noncompliant ? Derived class will be caught above //@violation CATCH_EXCPETIONS_IN_HIERACHICAL_ORDER
	{
	  // Any code here will be unreachable,
	}
}

