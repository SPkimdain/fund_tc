#include <stdlib.h>

/* MNTDA_015 - template */
template<typename T>
class MNTDA_015_Class {
public:
  MNTDA_015_Class(int size) : value(0) {
    if(size <= 1024) {
      value = new T();
    }
  }

  ~MNTDA_015_Class() {
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
  T* value;
};

void MNTDA_015_function(int flag) {
  MNTDA_015_Class<double> obj(10);


  obj.release(); //It's ok.

  if(flag) {
    MNTDA_015_Class<char> obj2(5);
    // Call destructor.
  } //@violation MISMATCH.NEW_TO_DELETE_ARRAY
}
