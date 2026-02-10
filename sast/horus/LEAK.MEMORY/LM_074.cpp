#include <list>

using namespace std;

typedef list<int*> IntPtrList;

/* LM_074 - container: list field */
class LM_074_Class {
public:

  void LM_074_function1(int* data) {
    values.push_front(data);
    return;
  }

  IntPtrList values;
};

void LM_074_function2(LM_074_Class& obj) {
  int* value = new int(10);
  obj.values.push_front(value);

  return; //It's ok.
}

void LM_074_function3(LM_074_Class& obj) {
  int* value = new int(10);
  obj.LM_074_function1(value);

  return; //It's ok.
}

void LM_074_function4() {
  int* value = new int(10);
  return; 
} //@violation LEAK.MEMORY



