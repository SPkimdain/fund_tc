//@checker DO_NOT_USE_USING_DIRECTIVE

#include <iostream>
#include <string>

namespace custom
{
	int temp;
};

using namespace std; // @violation DO_NOT_USE_USING_DIRECTIVE

void foo()
{
	int x = 0;
	using namespace custom; // @violation DO_NOT_USE_USING_DIRECTIVE
}

int main()
{
	std::string str;
	
	using std::string;	

	string str2("Test using namepsace.");
	

	using std::cout;
	cout << str2.c_str() << std::endl;

	
}
