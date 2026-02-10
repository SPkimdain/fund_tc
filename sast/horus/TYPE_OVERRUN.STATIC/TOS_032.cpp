#include <string.h>

/* TOS_032 - get value from virtual function */
struct TOS_032_Struct {
  int i;
  char c;
  long l;
  int arr[7];
};

class TOS_032_Base {
public:
  TOS_032_Base() : value(5) {}

  virtual int getValue() {
    return value; // return 5;
  }
private:
  int value;
};

class TOS_032_Derived : public TOS_032_Base {
public:
  TOS_032_Derived() : TOS_032_Base(), value2(10) {}

  virtual int getValue() {
    return value2; //return 10;
  }
  int value2;
};

void TOS_032_function(const char *msg) {
  TOS_032_Base* obj1 = new TOS_032_Base();
  TOS_032_Base* obj2 = new TOS_032_Derived();
  TOS_032_Struct sb;
  
  int index = 0;
  index = obj1->getValue(); //return 5;
  sb.arr[index] = 100; //It's ok.

  index = obj2->getValue(); //return 10;

  sb.arr[index] = 100; //@violation TYPE_OVERRUN.STATIC

  delete obj1;
  delete obj2;
}
