#include <stdlib.h>

/* MNATF_011 - object parameter */
class MNATF_011_Class {
public:
  MNATF_011_Class() : value(0) {}

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

void MNATF_011_function1(MNATF_011_Class& obj) {
  obj.release();
}

void MNATF_011_function2(){
  int* data = (int*)malloc(sizeof(int) * 5);
  int* data2 = new int[5];

  MNATF_011_Class obj;
  MNATF_011_Class obj2;

  obj.setValue(data);
  

  obj2.setValue(data2);
  
  MNATF_011_function1(obj); //It's ok.
  MNATF_011_function1(obj2); //@violation MISMATCH.NEW_ARRAY_TO_FREE

}



