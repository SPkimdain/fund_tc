//@checker BEWARE_OF_PRECISION_LOSS



using namespace std;

void func1(float x)
{
	x = x -1.0;
}

void func2(double x)
{
	x = x+ 1.0;
}

int main()
{
	const int thrhld = 16777217;
	const int safe = 16777216;
	
	func1(thrhld); //@violation BEWARE_OF_PRECISION_LOSS
	func1(safe); /* safe의 값은 2^24승 이하이므로 문제 없음. */

	func2(thrhld); /* double이므로 문제 없음. */
	func2(safe); /* double이므로 문제 없음. 값도 2^24승 이하. */

	func1(1234567890); //@violation BEWARE_OF_PRECISION_LOSS

	int value1 = 1234567890;
	char value2 = 0;

	float fValue = 0.F;

	/* float형으로 암시적 변환이 일어남 */
	fValue = value1; //@violation BEWARE_OF_PRECISION_LOSS

	int test =  (int)fValue;

	float testf =  (float)value2;

	float testf2 =  (float)value1; //@violation BEWARE_OF_PRECISION_LOSS

	double dValue = 0.0;
	dValue = value1; /* double이 8byte인 경우 문제 없음 */

	long long value3 = 1234567890;
	float fValue2 = (float)value3; //@violation BEWARE_OF_PRECISION_LOSS

	float fValue3 = 16777217; //@violation BEWARE_OF_PRECISION_LOSS
	float fValue4 = 16777216;


}
