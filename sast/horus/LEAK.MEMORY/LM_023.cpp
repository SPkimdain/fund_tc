#include <stdexcept>

/* LM_023 - exception */
using namespace std;

namespace LM_023_Namespace {
  class LM_023_Exception : public exception {
  public:
    void print();
    
  };

  int LM_023_function1(int value);
  bool LM_023_function2();

  void LM_023_Exception::print()
  {
    int x = 0;
  }

  int LM_023_function1(int value)
  {
    if(value == 10)
    {
      throw LM_023_Exception();
    }

    return value * 2;
  }

  bool LM_023_function2()
  {
    int value = 0;
    int* ptr = new int(10);
    value = LM_023_function1(20);

    value = 0;
    try
    {      
      value = LM_023_function1(10);
      delete ptr;
    }
    catch(LM_023_Exception& e)
    {
      //ptr is leaked.
      return false; 
    } //@violation LEAK.MEMORY
    return true;
  } 
}
