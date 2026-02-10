#include <string.h>

/* UDD_032 - get value from virtual function */
class UDD_032_Base {
public:
  UDD_032_Base() : value(5) {}

  virtual int getValue() {
    return value; // return 5;
  }
private:
  int value;
};

class UDD_032_Derived : public UDD_032_Base {
public:
  UDD_032_Derived() : UDD_032_Base(), value2(-10) {}

  virtual int getValue() {
    return value2; //return -10;
  }
  int value2;
};

void UDD_032_function(const char *msg) {
  UDD_032_Base* obj1 = new UDD_032_Base();
  UDD_032_Base* obj2 = new UDD_032_Derived();
  int* arr = new int[7];
  if(arr == 0) {
    return;
  }

  
  int index = 0;
  index = obj1->getValue(); //return 5;
  arr[index] = 100; //It's ok.

  index = obj2->getValue(); //return -10;

  arr[index] = 100; //@violation UNDERRUN.DYNAMIC

  delete obj1;
  delete obj2;
  delete[] arr;
}
