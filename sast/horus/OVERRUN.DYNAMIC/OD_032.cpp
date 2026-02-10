#include <string.h>

/* OD_032 - get value from virtual function */
class OD_032_Base {
public:
  OD_032_Base() : value(5) {}

  virtual int getValue() {
    return value; // return 5;
  }
private:
  int value;
};

class OD_032_Derived : public OD_032_Base {
public:
  OD_032_Derived() : OD_032_Base(), value2(10) {}

  virtual int getValue() {
    return value2; //return 10;
  }
  int value2;
};

void OD_032_function(const char *msg) {
  OD_032_Base* obj1 = new OD_032_Base();
  OD_032_Base* obj2 = new OD_032_Derived();
  int* arr = new int[7];
  if(arr == 0) {
    return;
  }

  
  int index = 0;
  index = obj1->getValue(); //return 5;
  arr[index] = 100; //It's ok.

  index = obj2->getValue(); //return 10;

  arr[index] = 100; //@violation OVERRUN.DYNAMIC

  delete obj1;
  delete obj2;
  delete[] arr;
}
