#include <stdlib.h>

/* MNTDA_014 - constructor / destructor */
class MNTDA_014_Class {
public:
  MNTDA_014_Class(int size) : value(0) {
    if(size <= 1024) {
      value = new int('x');
    }
  }

  ~MNTDA_014_Class() {
    if(value != 0) {
      delete[] value; 
    }
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

void MNTDA_014_function(int flag) {
  MNTDA_014_Class obj(10);
  

  obj.release(); //It's ok.

  if(flag) {
    MNTDA_014_Class obj2(5);
    // Call destructor.
  } //@violation MISMATCH.NEW_TO_DELETE_ARRAY

}
