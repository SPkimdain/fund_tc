//@checker AVOID_THROWING_GENERIC_EXCEPTION

#include <exception>
#include <stdexcept>

class AvoidThrowingGenericException{
public:
	void faultMethod();
	void normalMethod();
	
	int k;
	
};

void AvoidThrowingGenericException::faultMethod()
{
	k = 0;
	throw new std::exception();	//@violation AVOID_THROWING_GENERIC_EXCEPTION
}

void AvoidThrowingGenericException::normalMethod()
{
	k = 0;
	throw new std::out_of_range("Really?");
}