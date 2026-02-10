#include <stdlib.h>

/* MMTDA_011 - object parameter */
class MMTDA_011_Class {
public:
  MMTDA_011_Class() : value(0) {}

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

void MMTDA_011_function1(MMTDA_011_Class& obj) {
  obj.release();
}

void MMTDA_011_function2(){
  int* data = new int[10];
  int* data2 = (int*)malloc(sizeof(int) * 5);

  MMTDA_011_Class obj;
  MMTDA_011_Class obj2;

  obj.setValue(data);
  

  obj2.setValue(data2);
  
  MMTDA_011_function1(obj); //It's ok.
  MMTDA_011_function1(obj2); //@violation MISMATCH.MALLOC_TO_DELETE_ARRAY

}



