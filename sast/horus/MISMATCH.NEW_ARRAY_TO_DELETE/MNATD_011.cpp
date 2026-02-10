#include <stdlib.h>

/* MNATD_011 - object parameter */
class MNATD_011_Class {
public:
  MNATD_011_Class() : value(0) {}

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

void MNATD_011_function1(MNATD_011_Class& obj) {
  obj.release();
}

void MNATD_011_function2(){
  int* data = new int(10);
  int* data2 = new int[5];

  MNATD_011_Class obj;
  MNATD_011_Class obj2;

  obj.setValue(data);
  

  obj2.setValue(data2);
  
  MNATD_011_function1(obj); //It's ok.
  MNATD_011_function1(obj2); //@violation MISMATCH.NEW_ARRAY_TO_DELETE

}



