#include <list>

using namespace std;

/* LM_042 - container: list field */
class LM_042_Class {
  typedef list<int*> IntPtrList;
public:
  int LM_042_function1(int size, bool flag) {
    int* data = new int[size];

    if(flag == true) {
      ipl.push_front(data);
      return 1;
    }

    return 0;
  } //@violation LEAK.MEMORY
private:
  IntPtrList ipl;
};

