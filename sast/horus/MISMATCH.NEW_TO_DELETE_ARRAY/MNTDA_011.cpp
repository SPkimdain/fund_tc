#include <stdlib.h>

/* MNTDA_011 - object parameter */
class MNTDA_011_Class {
public:
  MNTDA_011_Class() : value(0) {}

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

void MNTDA_011_function1(MNTDA_011_Class& obj) {
  obj.release();
}

void MNTDA_011_function2(){
  int* data = new int[10];
  int* data2 = new int(99);

  MNTDA_011_Class obj;
  MNTDA_011_Class obj2;

  obj.setValue(data);
  

  obj2.setValue(data2);
  
  MNTDA_011_function1(obj); //It's ok.
  MNTDA_011_function1(obj2); //@violation MISMATCH.NEW_TO_DELETE_ARRAY

}



