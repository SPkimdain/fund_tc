#include <stdlib.h>

/* MNTF_015 - template */
template<typename T>
class MNTF_015_Class {
public:
  MNTF_015_Class(int size) : value(0) {
    if(size <= 1024) {
      value = new T();
    }
  }

  ~MNTF_015_Class() {
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
  T* value;
};

void MNTF_015_function(int flag) {
  MNTF_015_Class<double> obj(10);


  obj.release(); //It's ok.

  if(flag) {
    MNTF_015_Class<char> obj2(5);
    // Call destructor.
  } //@violation MISMATCH.NEW_TO_FREE
}
