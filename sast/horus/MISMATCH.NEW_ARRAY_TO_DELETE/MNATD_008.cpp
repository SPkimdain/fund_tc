#include <stdlib.h>

/* MNATD_008 - field */
class MNATD_008_Class {
public:
  MNATD_008_Class() : value(0) {}

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

void MNATD_008_function(){
  int* data = new int(10);
  int* data2 = new int[10];
  
  MNATD_008_Class obj;

  obj.setValue(data);
  obj.release(); //It's ok.

  obj.setValue(data2);
  obj.release(); //@violation MISMATCH.NEW_ARRAY_TO_DELETE
}


