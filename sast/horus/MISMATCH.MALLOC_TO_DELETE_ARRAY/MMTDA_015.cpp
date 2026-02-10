#include <stdlib.h>

/* MMTDA_015 - template */
template<typename T>
class MMTDA_015_Class {
public:
  MMTDA_015_Class(int size) : value(0) {
    if(size <= 1024) {
      value = (T*)malloc(sizeof(T) * size);
    }
  }

  ~MMTDA_015_Class() {
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
  T* value;
};

void MMTDA_015_function(int flag) {
  MMTDA_015_Class<double> obj(10);


  obj.release(); //It's ok.

  if(flag) {
    MMTDA_015_Class<char> obj2(5);
    // Call destructor.
  } //@violation MISMATCH.MALLOC_TO_DELETE_ARRAY
}
