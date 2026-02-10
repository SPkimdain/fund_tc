#include <stdlib.h>

/* MNTF_011 - object parameter */
class MNTF_011_Class {
public:
  MNTF_011_Class() : value(0) {}

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

void MNTF_011_function1(MNTF_011_Class& obj) {
  obj.release();
}

void MNTF_011_function2(){
  int* data = (int*)malloc(sizeof(int) * 5);
  int* data2 = new int(99);

  MNTF_011_Class obj;
  MNTF_011_Class obj2;

  obj.setValue(data);
  

  obj2.setValue(data2);
  
  MNTF_011_function1(obj); //It's ok.
  MNTF_011_function1(obj2); //@violation MISMATCH.NEW_TO_FREE

}



