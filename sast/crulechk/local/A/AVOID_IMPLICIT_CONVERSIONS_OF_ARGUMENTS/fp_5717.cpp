//@checker AVOID_IMPLICIT_CONVERSIONS_OF_ARGUMENTS
#include <string>

class Base
{
	int a;
	public :
	void test (Base * b);
	void test2(std::string str);
};
class Derived : public Base
{
	int b;
};
void AVDICOARG_001_function1(Base * b);

void AVDICOARG_001_function2(std::string str);
void AVDICOARG_001_function3(float a);
void AVDICOARG_001_function4() {
  
  
	Base *ptr = new Derived();
	Derived* d = new Derived();
	Base* b = new Base();
	d->test(d); 
	b->test(ptr);
	b->test(d); 
	AVDICOARG_001_function1(ptr);
	AVDICOARG_001_function1(d);
	
	AVDICOARG_001_function2((char*)"Test"); //@violation AVOID_IMPLICIT_CONVERSIONS_OF_ARGUMENTS
	AVDICOARG_001_function3((int)1);
	


}
