#include <stdlib.h>

/* MMTDA_014 - constructor / destructor */
class MMTDA_014_Class {
public:
  MMTDA_014_Class(int size) : value(0) {
    if(size <= 1024) {
      value = (int*)malloc(sizeof(int) * size);
    }
  }

  ~MMTDA_014_Class() {
    if(value != 0) {
      delete[] value; 
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

void MMTDA_014_function(int flag) {
  MMTDA_014_Class obj(10);
  

  obj.release(); //It's ok.

  if(flag) {
    MMTDA_014_Class obj2(5);
    // Call destructor.
  } //@violation MISMATCH.MALLOC_TO_DELETE_ARRAY

}
