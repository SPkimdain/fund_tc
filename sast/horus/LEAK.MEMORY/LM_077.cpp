#include <memory.h>
#include <stdlib.h>
#include <vector>

using namespace std;

/* LM_077 - base to derived member get. */
class LM_077_Base {
public:

private:
  LM_077_Base* prev;
};

class LM_077_Class : public LM_077_Base {
public:
  LM_077_Class() : LM_077_Base(), arr(0) {}
  LM_077_Class(int* val) : LM_077_Base(), arr(val) {}

  void setData(int* val) {
    arr = val;
  }

private:
  int* arr;
};

class LM_077_Class2 {
public:
  LM_077_Class2(LM_077_Base* o) : obj(o) {}

  LM_077_Class* getClass() {     
    return static_cast<LM_077_Class*>(obj); //Base to derived casting.
  }

private:
  LM_077_Base* obj;
};

class LM_077_Class3 {
public:
  
  LM_077_Class2 getClass2() {
    return LM_077_Class2(&cls1);
  }  

private:
  LM_077_Class cls1;
};


class LM_077_Class4 {
public:

  void LM_077_function(int data, int flag) {
    LM_077_Class2 obj2 = cls3.getClass2(); //LM_077_Class object is a cls3's member.

    if(flag > 10) {
      LM_077_Class* obj1 = obj2.getClass();


      int* val = new int(data);

      obj1->setData(val); //It's ok.
    }
    return;
  }

  LM_077_Class3 cls3;
};


void LM_077_function2() {
  int * ptr = (int*)malloc(4);
} //@violation LEAK.MEMORY

