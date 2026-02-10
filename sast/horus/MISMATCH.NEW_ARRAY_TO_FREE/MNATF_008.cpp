#include <stdlib.h>

/* MNATF_008 - field */
class MNATF_008_Class {
public:
  MNATF_008_Class() : value(0) {}

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

void MNATF_008_function(){
  int* data = (int*)malloc(sizeof(int) * 5);
  int* data2 = new int[10];
  
  MNATF_008_Class obj;

  obj.setValue(data);
  obj.release(); //It's ok.

  obj.setValue(data2);
  obj.release(); //@violation MISMATCH.NEW_ARRAY_TO_FREE
}


