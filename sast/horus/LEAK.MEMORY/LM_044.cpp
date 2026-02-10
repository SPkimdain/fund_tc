#include <set>

using namespace std;

/* LM_044 - container: set field */
class LM_044_Class {
  typedef set<int*> IntPtrSet;
public:
  int LM_044_function1(int size, bool flag) {
    int* data = new int[size];

    if(flag == true) {
      ips.insert(data);
      return 1;
    }

    return 0;
  } //@violation LEAK.MEMORY
private:
  IntPtrSet ips;
};

