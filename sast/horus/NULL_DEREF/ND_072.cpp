#include <stdio.h>
#include <string.h>
#include <iostream>

/* ND_072 - complex5 */

using std::cout;

class ND_072_Class1 {
public:
  ND_072_Class1(bool f) : flag(f), ptr(0), ptr2(0) {}

  void setPtr(int* p) {
    if(flag == true) {
      ptr = p;
    }
    else {
      ptr2 = p;
    }
  }

  int* getPtr() {
    if(flag == true) {
      return ptr;
    }
    else {
      return ptr2;
    }
  }

private:
  bool flag;
  int* ptr;
  int* ptr2;
};


class ND_072_Class2 {
public:
  ND_072_Class2() : offset(0), obj(false), obj2(true), obj3(true) {}

  int accessObj(int target);
  void setObj(int target, int* ptrVal, int* ptrValAlter);

private:
  int offset;
  ND_072_Class1 obj;
  ND_072_Class1 obj2;
  ND_072_Class1 obj3;
};


int ND_072_Class2::accessObj(int target) {
  if(offset < 10) {
    offset += 2;
  }


  for(int iter = 0; iter < 10; ++iter) {
    if(iter == 3) {
      switch(target) {
      case 0:
        return *(obj.getPtr());
      case 1:
        return *(obj2.getPtr());
      default:
        break;
      }
    }
  }

  return 0;
}

void ND_072_Class2::setObj(int target, int* ptrVal, int* ptrValAlter) {
  if(target > 2) {
    return;
  }

  switch(target) {
  case 0:
    obj.setPtr(ptrVal);
    break;
  case 1:
    obj2.setPtr(ptrVal);
    break;
  case 2:
    obj3.setPtr(ptrValAlter);
    break;
  }

}

bool ND_072_function1(int flag, ND_072_Class2& out, int* first1, int *first2, int* second, int* third) {
  if(flag > 0) {
    out.setObj(0, first1, first2); //obj::ptr2 = v;

    out.setObj(1, 0, second); //obj2::ptr = 0;

    out.setObj(2, 0, third); //obj3::ptr = xxx;
  }
  return true;
}

void ND_072_function2(int max, int flag, int flag2, char* str) {
  ND_072_Class2 nd;
  int v = 10;
  int v2 = 20;

  int xx = 30;
  int xxx = 40;

  if(strcmp("Test", str) == 0) {
    bool ret = ND_072_function1(20, nd, &v, &v2, &xx, &xxx);

    
    for(int iter = 0; iter < max; ++iter) {
      if(flag2 == true) {

        if(flag == true) {
          cout << nd.accessObj(0); //It's ok.
        }
        else {
          cout << nd.accessObj(1); //@violation NULL_DEREF
        }
        break;
      }
    }
    
  }
}
