#include <string.h>
#include <stdlib.h>

/* UAF_033 - memory function, strcpy */
class UAF_033_Class {
public:
  UAF_033_Class(int size) : dst(0), test(false) {
    dst = new char[size];
  }

  ~UAF_033_Class() {
    if(test == false) {
      delete[] dst;
    }
  }

  void release() {
    test = true;
    delete[] dst;
  }

  char* getDst() { return dst; }
private:
  char* dst;
  bool test;
};

void UAF_033_function1(char* src) {
  UAF_033_Class obj(256);
  UAF_033_Class obj2(256);

  strcpy(obj.getDst(), src);

  obj2.release();

  strcpy(obj2.getDst(), src); //@violation USE_AFTER_FREE
}

