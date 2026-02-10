#include <string.h>

/* TUDS_032 - get value from virtual function */
struct TUDS_032_Struct {
  int i;
  char c;
  long l;
  int arr[7];
};

class TUDS_032_Base {
public:
  TUDS_032_Base() : value(5) {}

  virtual int getValue() {
    return value; // return 5;
  }
private:
  int value;
};

class TUDS_032_Derived : public TUDS_032_Base {
public:
  TUDS_032_Derived() : TUDS_032_Base(), value2(-10) {}

  virtual int getValue() {
    return value2; //return -10;
  }
  int value2;
};

void TUDS_032_function(const char *msg) {
  TUDS_032_Base* obj1 = new TUDS_032_Base();
  TUDS_032_Base* obj2 = new TUDS_032_Derived();
  TUDS_032_Struct sb;
  
  int index = 0;
  index = obj1->getValue(); //return 5;
  sb.arr[index] = 100; //It's ok.

  index = obj2->getValue(); //return -10;

  sb.arr[index] = 100; //@violation TYPE_UNDERRUN.STATIC

  delete obj1;
  delete obj2;
}
