#include <string.h>
#include <stdlib.h>

/* UAF_039 - memory function, strcpy, multiple */
class UAF_039_Class {
public:
  UAF_039_Class(int size) : dst(0), test(false) {
    dst = new char[size];
  }

  ~UAF_039_Class() {
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

void UAF_039_function1(UAF_039_Class& obj, char* src) {
  strcpy(obj.getDst(), src);
}

void UAF_039_function2(char* src) {
  UAF_039_Class obj(256);
  UAF_039_Class obj2(256);

  UAF_039_function1(obj, src); //It's ok.

  obj2.release();

  UAF_039_function1(obj2, src); //@violation USE_AFTER_FREE

}
