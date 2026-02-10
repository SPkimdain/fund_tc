//@checker DO_NOT_USE_HARD_CODING.CALL
#include <vector>
using namespace std;

extern void test(const char* str, char* str2) {};

class Test {
	
	public :
		Test(){}
		void test2(const char* str){
			return;
		}
};

 
void DNUHCDC_001_function() {
	char str[20];
	vector<char*> vec;
	Test *t1 = new Test();
	test("hardcoding", str);	//@violation DO_NOT_USE_HARD_CODING.CALL
	t1->test2("hardcoding");	//@violation DO_NOT_USE_HARD_CODING.CALL
	vec.push_back("hardcoding");	//@violation DO_NOT_USE_HARD_CODING.CALL
}
