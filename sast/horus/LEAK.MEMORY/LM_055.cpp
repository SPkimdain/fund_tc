
/* Only c++11 testcases */
/* LM_055 - unique ptr */

#if _MSC_VER >= 1800 || GCC_VERSION >= 40200
#include <memory>

struct LM_55_Struct {
  LM_55_Struct(int _x, int _y) : x(_x), y(_y) {}
  
  int x;
  int y;
};

class LM_055_Class {
public:
  LM_055_Class() : obj() {}
  
  void LM_055_function() {
    obj.reset(new LM_55_Struct(5, 10));
  }
  
private:
  std::unique_ptr<LM_55_Struct> obj;
};

void LM_055_function2() {
  std::unique_ptr<char[]> buf(new char[10]);
} //It's ok.

#endif


void LM_055_function3() {
  int* ptr = new int(10);
} //@violation LEAK.MEMORY
