#include <stdlib.h>

/* DF_012 - method call */
class DF_012_Class1 {
public:
  DF_012_Class1() : value(0) {
    value = new int(10);
  }
  
  void release() {
    delete value;
  }
  
  void test() {
    //Same symbol
    release(); //It's ok.
  }

private:
  int* value;
};

void DF_012_function(bool flag) {
  if(flag > 0) {
    DF_012_Class1 obj;
    obj.test();    
  } 
}

int DF_012_function2(int flag) {
  int * ptr = (int*)malloc(4); 
  free(ptr);
  free(ptr); //@violation DOUBLE_FREE
  return flag;
} 
