#include <stdlib.h>

/* MNATD_014 - constructor / destructor */
class MNATD_014_Class {
public:
  MNATD_014_Class(int size) : value(0) {
    if(size <= 1024) {
      value = new int[size];
    }
  }

  ~MNATD_014_Class() {
    if(value != 0) {
      delete value; 
    }
  }

  void release() {
    if(value != 0) {
      delete[] value; //It's ok.
      value = 0;
    }
  }

private:
  int* value;
};

void MNATD_014_function(int flag) {
  MNATD_014_Class obj(10);
  

  obj.release(); //It's ok.

  if(flag) {
    MNATD_014_Class obj2(5);
    // Call destructor.
  } //@violation MISMATCH.NEW_ARRAY_TO_DELETE

}
