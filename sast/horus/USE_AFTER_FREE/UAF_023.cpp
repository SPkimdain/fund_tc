#include <stdexcept>

/* UAF_023 - exception */
using namespace std;

namespace UAF_023_Namespace {
class UAF_023_Exception : public exception
{
public:
  void print();
    
};

int UAF_023_function1(int value);
void UAF_023_function2();

void UAF_023_Exception::print()
{
  int x = 0;
}

int UAF_023_function1(int value)
{
  if(value == 10)
  {
    throw UAF_023_Exception();
  }

  return value * 2;
}

void UAF_023_function2()
{
  int value = 0;
  int* ptr = new int(10);
  value = UAF_023_function1(20);

  value = 0;
  try
  {
    delete ptr;    
    value = UAF_023_function1(10);
    
    ptr = new int(5);
    delete ptr;
  }
  catch(UAF_023_Exception& e)
  {
    *ptr = 10; //@violation USE_AFTER_FREE
  }    
}
}
