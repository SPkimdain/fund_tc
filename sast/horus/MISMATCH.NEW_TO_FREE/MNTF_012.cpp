#include <stdlib.h>

/* MNTF_012 - object parameter2 */
class MNTF_012_Class {
public:
  MNTF_012_Class() : value(0) {}

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

class MNTF_012_Class2 {
public:
  MNTF_012_Class2() : obj() {}

  void transaction(int* value) {
    obj.setValue(value);

    obj.release();
  }
private:
  MNTF_012_Class obj;
};

void MNTF_012_function1(MNTF_012_Class2& obj, int* value) {
  obj.transaction(value);
}

void MNTF_012_function2(){
  int* data = (int*)malloc(sizeof(int) * 10);
  int* data2 = new int(5);

  MNTF_012_Class2 obj;
  MNTF_012_Class2 obj2;

  MNTF_012_function1(obj, data); //It's ok.
  MNTF_012_function1(obj2, data2); //@violation MISMATCH.NEW_TO_FREE

}



