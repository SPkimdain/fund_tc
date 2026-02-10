//@checker ONLY_LOOP_COUNT_INC_DEC

#include <string>
#include <vector>

using namespace std;

class FP5725{
public:
	void foo();
	
};

void FP5725::foo(){
	vector<string> myVector;
	myVector.push_back("hello");
	
	vector<string>::iterator vecIt;
	for(vecIt = myVector.begin(); vecIt != myVector.end(); vecIt++) {
		// blahblah.....
	}
}
