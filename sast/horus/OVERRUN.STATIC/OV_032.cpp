#include <string.h>

/* OV_032 - get value from virtual function */
class OV_032_Base {
public:
  OV_032_Base() : value(5) {}

  virtual int getValue() {
    return value; // return 5;
  }
private:
  int value;
};

class OV_032_Derived : public OV_032_Base {
public:
  OV_032_Derived() : OV_032_Base(), value2(10) {}

  virtual int getValue() {
    return value2; //return 10;
  }
  int value2;
};

void OV_032_function(const char *msg) {
  OV_032_Base* obj1 = new OV_032_Base();
  OV_032_Base* obj2 = new OV_032_Derived();
  int arr[7] = { 0, };
  
  int index = 0;
  index = obj1->getValue(); //return 5;
  arr[index] = 100; //It's ok.

  index = obj2->getValue(); //return 10;

  arr[index] = 100; //@violation OVERRUN.STATIC

  delete obj1;
  delete obj2;
}
