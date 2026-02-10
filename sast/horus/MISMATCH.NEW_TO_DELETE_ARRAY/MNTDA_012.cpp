#include <stdlib.h>

/* MNTDA_012 - object parameter2 */
class MNTDA_012_Class {
public:
  MNTDA_012_Class() : value(0) {}

  void setValue(int* v) {
    value = v;
  }

  void release() {
    if(value != 0) {
      delete[] value;
      value = 0;
    }
  }

private:
  int* value;
};

class MNTDA_012_Class2 {
public:
  MNTDA_012_Class2() : obj() {}

  void transaction(int* value) {
    obj.setValue(value);

    obj.release();
  }
private:
  MNTDA_012_Class obj;
};

void MNTDA_012_function1(MNTDA_012_Class2& obj, int* value) {
  obj.transaction(value);
}

void MNTDA_012_function2(){
  int* data = new int[10];
  int* data2 = new int(5);

  MNTDA_012_Class2 obj;
  MNTDA_012_Class2 obj2;

  MNTDA_012_function1(obj, data); //It's ok.
  MNTDA_012_function1(obj2, data2); //@violation MISMATCH.NEW_TO_DELETE_ARRAY

}



