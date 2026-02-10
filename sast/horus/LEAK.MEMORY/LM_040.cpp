#include <stdexcept>

/* LM_040 - exception2 */
using namespace std;

class LM_040_Class {
public:
  LM_040_Class(bool throwException) {
    buffer = new char[1024];
    if(throwException == true) {
      throw std::runtime_error("ctor failed.");
    }
  }

  ~LM_040_Class() {
    delete[] buffer;
  }
private:
  char* buffer;
};

void LM_040_function(int flag) {
  int check = 0;
  if(flag > 0) {
    LM_040_Class obj(false);
    check++;
  } //It's ok.
  else {
    //obj.buffer is leaked.
    LM_040_Class obj2(true); 
    check++;
  }

  check++;

  return;
} //@violation LEAK.MEMORY

