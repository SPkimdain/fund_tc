#include <stdlib.h>

/* MNATD_012 - object parameter2 */
class MNATD_012_Class {
public:
  MNATD_012_Class() : value(0) {}

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

class MNATD_012_Class2 {
public:
  MNATD_012_Class2() : obj() {}

  void transaction(int* value) {
    obj.setValue(value);

    obj.release();
  }
private:
  MNATD_012_Class obj;
};

void MNATD_012_function1(MNATD_012_Class2& obj, int* value) {
  obj.transaction(value);
}

void MNATD_012_function2(){
  int* data = new int(10);
  int* data2 = new int[5];

  MNATD_012_Class2 obj;
  MNATD_012_Class2 obj2;

  MNATD_012_function1(obj, data); //It's ok.
  MNATD_012_function1(obj2, data2); //@violation MISMATCH.NEW_ARRAY_TO_DELETE

}



