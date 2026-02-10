#include <stdlib.h>

/* MNTF_008 - field */
class MNTF_008_Class {
public:
  MNTF_008_Class() : value(0) {}

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

void MNTF_008_function(){
  int* data = (int*)malloc(sizeof(int) * 10);
  int* data2 = new int(5);
  
  MNTF_008_Class obj;

  obj.setValue(data);
  obj.release(); //It's ok.

  obj.setValue(data2);
  obj.release(); //@violation MISMATCH.NEW_TO_FREE
}


