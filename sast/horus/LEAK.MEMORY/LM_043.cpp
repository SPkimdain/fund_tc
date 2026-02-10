#include <vector>

using namespace std;

/* LM_043 - container: vector field */
class LM_043_Class {
  typedef vector<int*> IntPtrVec;
public:
  int LM_043_function1(int size, bool flag) {
    int* data = new int[size];

    if(flag == true) {
      ipv.push_back(data);
      return 1;
    }

    return 0;
  } //@violation LEAK.MEMORY
private:
  IntPtrVec ipv;
};

