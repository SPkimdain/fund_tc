#include <iostream>
#include <stdarg.h>
/* LM_065 - assign twice - static field */

class LM_065_Class {
public:
  LM_065_Class(int x) {
    LM_065_sVar = new int(10);
    *LM_065_sVar = x;
  }
  
  ~LM_065_Class() {
    if(LM_065_sVar != 0) {
      delete LM_065_sVar;
      LM_065_sVar = 0;
    }
  }
  
  static int* LM_065_sVar;  
};

int* LM_065_Class::LM_065_sVar = 0;

class LM_065_Class2 {
public:
  LM_065_Class2() : lmObj(0), lmObj2(0) {}
  ~LM_065_Class2() {
    if(lmObj != 0) {
      delete lmObj;
      lmObj = 0;
    }
    
    if(lmObj2 != 0) {
      delete lmObj2;
      lmObj2 = 0;
    }
  }
  
  int LM_065_function1(int flag, int x, int y, int z);
  
  LM_065_Class* lmObj;
  LM_065_Class* lmObj2;
};

class LM_065_Class_Allocator{
public:
  static LM_065_Class* gen(int val) {
    return alloc<LM_065_Class>(val);
  }
  
  template<typename T, typename... ARGS>
  static T* alloc(ARGS... args) {
    return new T(args...);
  }

};

LM_065_Class* LM_065_genObject(bool flag, bool flag2, int val) {
  if(val == 0) {
    return 0;
  }

  if(flag == true && flag2 == false) {
    return LM_065_Class_Allocator::gen(val);
  }

  return 0;
}

int LM_065_Class2::LM_065_function1(int flag, int x, int y, int z) {
  if(lmObj == 0) {
    return 1;
  }
  
  int *p = &z;
  if(x < 0 && y > 0 && z < 10){
    p = 0;
  }

  x = x + 1;

  y = y - 1;

  z = z - 10;

  if(x == 0) {
    
    if(y > -1) {
      
      if(z < 0) {
        lmObj = new LM_065_Class(10);
        switch(flag) {
        case 10:
          lmObj2 = LM_065_genObject(false, false, 10); //It's ok.
          return 2;

        case 20:
          lmObj2 = LM_065_genObject(true, false, 20); //Lost object.
          return 3;

        default:
          break;
        } //@violation LEAK.MEMORY

        return 1;
      }
    }
    ;
  }
  
  return 0;
} 

