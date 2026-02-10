#include <stdlib.h>

/* MMTD_012 - object parameter2 */
class MMTD_012_Class {
public:
  MMTD_012_Class() : value(0) {}

  void setValue(int* v) {
    value = v;
  }

  void release() {
    if(value != 0) {
      delete value;
      value = 0;
    }
  }

private:
  int* value;
};

class MMTD_012_Class2 {
public:
  MMTD_012_Class2() : obj() {}

  void transaction(int* value) {
    obj.setValue(value);

    obj.release();
  }
private:
  MMTD_012_Class obj;
};

void MMTD_012_function1(MMTD_012_Class2& obj, int* value) {
  obj.transaction(value);
}

void MMTD_012_function2(){
  int* data = new int(10);
  int* data2 = (int*)malloc(sizeof(int) * 5);

  MMTD_012_Class2 obj;
  MMTD_012_Class2 obj2;

  MMTD_012_function1(obj, data); //It's ok.
  MMTD_012_function1(obj2, data2); //@violation MISMATCH.MALLOC_TO_DELETE

}



