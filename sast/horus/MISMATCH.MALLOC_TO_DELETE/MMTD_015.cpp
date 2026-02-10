#include <stdlib.h>

/* MMTD_015 - template */
template<typename T>
class MMTD_015_Class {
public:
  MMTD_015_Class(int size) : value(0) {
    if(size <= 1024) {
      value = (T*)malloc(sizeof(T) * size);
    }
  }

  ~MMTD_015_Class() {
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
  T* value;
};

void MMTD_015_function(int flag) {
  MMTD_015_Class<double> obj(10);


  obj.release(); //It's ok.

  if(flag) {
    MMTD_015_Class<char> obj2(5);
    // Call destructor.
  } //@violation MISMATCH.MALLOC_TO_DELETE
}
