// @checker CRITICAL_VARIABLE_IN_PUBLIC
// CWE 766 case

using namespace std;

class CWE766Testcase
{
	int thisPrivate;
public :
	int password; // @violation CRITICAL_VARIABLE_IN_PUBLIC
	volatile int m_password2; // @violation CRITICAL_VARIABLE_IN_PUBLIC
	const int nonalarm;
	void test (int a, int b) 
	{
		
	}
	
	CWE766Testcase() : nonalarm(10)
	{
		
		password = 50;
	}
};