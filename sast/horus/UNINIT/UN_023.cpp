#pragma warning(disable : 4700)

#include <stdexcept>

/* UN_023 - exception */
using namespace std;

namespace UN_023_Namespace {
class UN_023_Exception : public exception
{
public:
  void print();
    
};

int UN_023_function1(int value);
void UN_023_function2();

void UN_023_Exception::print()
{
  int x = 0;
}

int UN_023_function1(int value)
{
  if(value == 10)
  {
    throw UN_023_Exception();
  }

  return value * 2;
}

void UN_023_function2()
{
  int value = 0;
  int p;
  value = UN_023_function1(20);

  value = 0;
  try
  {
    value = UN_023_function1(10);
    p = 0;
  }
  catch(UN_023_Exception& e)
  {
    value = p; //@violation UNINIT
  }
}

}
