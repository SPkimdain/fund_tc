#include <stdlib.h>

/* MNTF_014 - constructor / destructor */
class MNTF_014_Class {
public:
  MNTF_014_Class(int size) : value(0) {
    if(size <= 1024) {
      value = new int('x');
    }
  }

  ~MNTF_014_Class() {
    if(value != 0) {
      free(value);
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

void MNTF_014_function(int flag) {
  MNTF_014_Class obj(10);
  

  obj.release(); //It's ok.

  if(flag) {
    MNTF_014_Class obj2(5);
    // Call destructor.
  } //@violation MISMATCH.NEW_TO_FREE

}
