#include <stdlib.h>
#include <memory>
#include <cstring>

/* LM_054 - copy assign operator */
class LM_054_Class {
public:
  LM_054_Class() : length(0), data(0) {}
  LM_054_Class(size_t len) {
    length = len;
    data = new char[len]();
  }
  
  ~LM_054_Class() {
    delete[] data;
  }
  
  LM_054_Class& operator=(const LM_054_Class& rhs) {
    if(this != &rhs) {
      delete[] data;
      data = new char[rhs.length]();
      length = rhs.length;
      memcpy(data, rhs.data, sizeof(char) * length);
    }
    return *this;
  }
  
private:
  size_t length;
  char* data;
};

class LM_054_Class2 {
public:
  LM_054_Class2() {
    int v = 0;
    LM_054_Class emptyStr(1);        
    fStr = emptyStr;
    
    LM_054_function2();
    
  } //It's ok.
  
  void LM_054_function2() {
    int x = 0;
    x++;
  }

private:
  LM_054_Class fStr;
};

void LM_054_function3() {
  int* ptr = new int(10);
} //@violation LEAK.MEMORY
