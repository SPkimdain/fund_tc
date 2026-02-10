#include <stdlib.h>

/* MNATD_015 - template */
template<typename T>
class MNATD_015_Class {
public:
  MNATD_015_Class(int size) : value(0) {
    if(size <= 1024) {
      value = new T[size];
    }
  }

  ~MNATD_015_Class() {
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
  T* value;
};

void MNATD_015_function(int flag) {
  MNATD_015_Class<double> obj(10);


  obj.release(); //It's ok.

  if(flag) {
    MNATD_015_Class<char> obj2(5);
    // Call destructor.
  } //@violation MISMATCH.NEW_ARRAY_TO_DELETE
}
