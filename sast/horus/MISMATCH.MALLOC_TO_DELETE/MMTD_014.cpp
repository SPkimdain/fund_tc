#include <stdlib.h>

/* MMTD_014 - constructor / destructor */
class MMTD_014_Class {
public:
  MMTD_014_Class(int size) : value(0) {
    if(size <= 1024) {
      value = (int*)malloc(sizeof(int) * size);
    }
  }

  ~MMTD_014_Class() {
    if(value != 0) {
      delete value; 
    }
  }

  void release() {
    if(value != 0) {
      free(value); //It's ok.
      value = 0;
    }
  }

private:
  int* value;
};

void MMTD_014_function(int flag) {
  MMTD_014_Class obj(10);
  

  obj.release(); //It's ok.

  if(flag) {
    MMTD_014_Class obj2(5);
    // Call destructor.
  } //@violation MISMATCH.MALLOC_TO_DELETE

}
