#include <stdexcept>

/* OV_023 - exception */
using namespace std;

namespace OV_023_Namespace {
class OV_023_Exception : public exception
{
public:
  void print();
    
};

int OV_023_function1(int value);
void OV_023_function2();

void OV_023_Exception::print()
{
  int x = 0;
}

int OV_023_function1(int value)
{
  if(value == 10)
  {
    throw OV_023_Exception();
  }

  return value * 2;
}

void OV_023_function2()
{
  int value = 0;
  int p[3] = { 0, };
  value = OV_023_function1(20);

  value = 0;
  try
  {
    value = OV_023_function1(10);
  }
  catch(OV_023_Exception& e)
  {
    p[value + 4] = 10; //@violation OVERRUN.STATIC
  }
}

}
