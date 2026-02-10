#ifdef _WIN32
#pragma warning(disable:4996)
#endif

#include <string.h>
#include <stdlib.h>

/* UAF_042 - memory function, strncat */
class UAF_042_Class {
public:
  UAF_042_Class(char* str) : src(0), size(0), test(false) {
    size = strlen(str);
    src = new char[size + 1];
    strcpy(src, str);
  }

  ~UAF_042_Class() {
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

class UAF_042_Access {
public:
  int access(char* dst, UAF_042_Class* obj, int switchVal) {
    int ret = 0;
    if(switchVal > 100) {
      ret++;
      return ret;
    }
    else {
      ret += 2;

      lastObj = obj;
      
      if(lastObj != 0) {
        strncat(dst, lastObj->getSrc(), lastObj->getSize());
      }

      return ret;
    }
  }

private:
  UAF_042_Class* lastObj;
};

void UAF_042_function1(UAF_042_Access& acc, char* dst, UAF_042_Class* obj) {
  if(dst == 0) {
    return;
  }

  if(obj == 0) {
    return;
  }
  
  acc.access(dst, obj, 1);
  
}


enum class UAF_042_Type { ENGINE, MODULE, CLASS, PACKAGE, NONE };

void UAF_042_function5(UAF_042_Type type) {
  char* buf = new char[256];
  if(buf == 0) {
    return;
  }

  UAF_042_Class obj2("testtest");

  UAF_042_Class obj3("checkVal");

  UAF_042_Class obj4("1234567");

  UAF_042_Access acc;

  switch(type) {
  case UAF_042_Type::ENGINE: {
    UAF_042_Class obj("abcdef");

    UAF_042_function1(acc, buf, &obj); //It's ok.

    obj.release();
    break;
  }
  case UAF_042_Type::MODULE:
    UAF_042_function1(acc, buf, &obj2); //It's ok.
    break;

  case UAF_042_Type::CLASS:
    obj3.release();

    break;
  case UAF_042_Type::PACKAGE:
    obj4.release();
    break;
  default:
    break;
  }

  UAF_042_function1(acc, buf, &obj3); //@violation USE_AFTER_FREE

  delete[] buf;
}


