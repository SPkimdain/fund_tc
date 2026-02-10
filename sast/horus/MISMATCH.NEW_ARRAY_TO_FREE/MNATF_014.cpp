#include <stdlib.h>

/* MNATF_014 - constructor / destructor */
class MNATF_014_Class {
public:
  MNATF_014_Class(int size) : value(0) {
    if(size <= 1024) {
      value = new int[size];
    }
  }

  ~MNATF_014_Class() {
    if(value != 0) {
      free(value); 
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

void MNATF_014_function(int flag) {
  MNATF_014_Class obj(10);
  

  obj.release(); //It's ok.

  if(flag) {
    MNATF_014_Class obj2(5);
    // Call destructor.
  } //@violation MISMATCH.NEW_ARRAY_TO_FREE

}
