#include <stdlib.h>

/* MNTDA_008 - field */
class MNTDA_008_Class {
public:
  MNTDA_008_Class() : value(0) {}

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

void MNTDA_008_function(){
  int* data = new int[10];
  int* data2 = new int(5);
  
  MNTDA_008_Class obj;

  obj.setValue(data);
  obj.release(); //It's ok.

  obj.setValue(data2);
  obj.release(); //@violation MISMATCH.NEW_TO_DELETE_ARRAY
}


