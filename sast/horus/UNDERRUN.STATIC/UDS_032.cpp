#include <string.h>

/* UDS_032 - get value from virtual function */
class UDS_032_Base {
public:
  UDS_032_Base() : value(5) {}

  virtual int getValue() {
    return value; // return 5;
  }
private:
  int value;
};

class UDS_032_Derived : public UDS_032_Base {
public:
  UDS_032_Derived() : UDS_032_Base(), value2(-1) {}

  virtual int getValue() {
    return value2; //return -1;
  }
  int value2;
};

void UDS_032_function(const char *msg) {
  UDS_032_Base* obj1 = new UDS_032_Base();
  UDS_032_Base* obj2 = new UDS_032_Derived();
  int arr[7] = { 0, };
  
  int index = 0;
  index = obj1->getValue(); //return 5;
  arr[index] = 100; //It's ok.

  index = obj2->getValue(); //return -1;

  arr[index] = 100; //@violation UNDERRUN.STATIC

  delete obj1;
  delete obj2;
}
