#include <stdexcept>

/* ND_023 - exception */
using namespace std;

namespace ND_023_Namespace {
  class ND_023_Exception : public exception
  {
  public:
    void print();
    
  };

  int ND_023_depth01(int value);
  void ND_023_depth02();

  void ND_023_testFea02();

  void ND_023_Exception::print()
  {
    int x = 0;
  }

  int ND_023_depth01(int value)
  {
    if(value == 10)
    {
      throw ND_023_Exception();
    }

    return value * 2;
  }

  void ND_023_depth02()
  {
    int value = 0;
    int* ptr = 0;
    value = ND_023_depth01(20);

    value = 0;
    try
    {
      value = ND_023_depth01(10);
    }
    catch(ND_023_Exception& e)
    {
      *ptr = 10; //@violation NULL_DEREF
    }
  }
}
