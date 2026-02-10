#include <stdlib.h>

/* MNATF_012 - object parameter2 */
class MNATF_012_Class {
public:
  MNATF_012_Class() : value(0) {}

  void setValue(int* v) {
    value = v;
  }

  void release() {
    if(value != 0) {
      free(value);
      value = 0;
    }
  }

private:
  int* value;
};

class MNATF_012_Class2 {
public:
  MNATF_012_Class2() : obj() {}

  void transaction(int* value) {
    obj.setValue(value);

    obj.release();
  }
private:
  MNATF_012_Class obj;
};

void MNATF_012_function1(MNATF_012_Class2& obj, int* value) {
  obj.transaction(value);
}

void MNATF_012_function2(){
  int* data = (int*)malloc(sizeof(int) * 5);
  int* data2 = new int[5];

  MNATF_012_Class2 obj;
  MNATF_012_Class2 obj2;

  MNATF_012_function1(obj, data); //It's ok.
  MNATF_012_function1(obj2, data2); //@violation MISMATCH.NEW_ARRAY_TO_FREE

}



