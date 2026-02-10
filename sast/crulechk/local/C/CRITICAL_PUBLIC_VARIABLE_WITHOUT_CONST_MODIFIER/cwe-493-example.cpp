// @checker CRITICAL_PUBLIC_VARIABLE_WITHOUT_CONST_MODIFIER


using namespace std;

class CWE493Testcase
{
	int thisPrivate;
public :
	int password; // @violation CRITICAL_PUBLIC_VARIABLE_WITHOUT_CONST_MODIFIER
	volatile int password2; // @violation CRITICAL_PUBLIC_VARIABLE_WITHOUT_CONST_MODIFIER
	int price2;
	const int password3;
	void test (int a, int b) 
	{
		
	}
	
	CWE493Testcase() : password3(10)
	{
		
		password2 = 50;
	}
};