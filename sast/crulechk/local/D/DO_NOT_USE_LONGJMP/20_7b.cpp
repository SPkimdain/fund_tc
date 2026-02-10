//@checker DO_NOT_USE_LONGJMP

#include <csetjmp>

using namespace std;

static jmp_buf env;

class Counter {
  public:
    static int Instances;

    Counter() {Instances++;}
    ~Counter() {Instances--;}
  private:
    Counter(const Counter& that);
    Counter& operator=(const Counter& that);
};

int Counter::Instances = 0;
class Error {};

void func() {
    Counter c;
    //cout << "func(): Instances: " << Counter::Instances << endl;
    longjmp( env, 1); //@violation DO_NOT_USE_LONGJMP
}

int main() {

    //cout << "Before setjmp(): Instances: " << Counter::Instances << endl;
    if (setjmp(env) == 0) {
	func();
    } else {
		int a =1;
	//cout << "From longjmp(): Instances: " << Counter::Instances << endl;
    }

	int a =2 ;
    //cout << "After longjmp(): Instances: " << Counter::Instances << endl;
}

