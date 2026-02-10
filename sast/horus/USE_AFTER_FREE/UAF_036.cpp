#include <string.h>
#include <stdlib.h>

/* UAF_036 - memory function, strncat */
class UAF_036_Class {
public:
  UAF_036_Class(char* str) : src(0), size(0), test(false) {
    size = strlen(str);
    src = new char[size + 1];
    strcpy(src, str);
  }

  ~UAF_036_Class() {
    if(test == false) {
      delete[] src;
    }
  }

  void release() {
    test = true;
    delete[] src;
  }

  char* getSrc() { return src; }
  int getSize() { return size; }
private:
  char* src;
  int size;
  bool test;
};

void UAF_036_function2() {
  char* buf = new char[256];
  if(buf == 0) {
    return;
  }

  UAF_036_Class obj("abcdef");
  UAF_036_Class obj2("testtest");

  strncat(buf, obj.getSrc(), obj.getSize());

  obj2.release();

  strncat(buf, obj2.getSrc(), obj2.getSize()); //@violation USE_AFTER_FREE

  delete[] buf;
}
