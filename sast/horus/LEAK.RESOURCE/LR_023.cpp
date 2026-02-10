#include <stdexcept>
#include <stdio.h>

/* LR_023 - exception */
using namespace std;

namespace LR_023_Namespace {
  class LR_023_Exception : public exception
  {
  public:
    void print();
    
  };

  int LR_023_function1(int value);
  bool LR_023_function2();


  void LR_023_Exception::print()
  {
    int x = 0;
  }

  int LR_023_function1(int value)
  {
    if(value == 10)
    {
      throw LR_023_Exception();
    }

    return value * 2;
  }

  bool LR_023_function2()
  {
    int value = 0;
    FILE* file = fopen("test.txt", "w");
    value = LR_023_function1(20);

    value = 0;
    try
    {      
      value = LR_023_function1(10);
      fclose(file);
    }
    catch(LR_023_Exception& e)
    {
      //file is leaked.
      return false; 
    } //@violation LEAK.RESOURCE
    return true;
  } 
}
