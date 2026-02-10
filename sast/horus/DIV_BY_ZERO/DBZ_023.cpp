#include <stdexcept>

/* DBZ_023 - exception */
using namespace std;

namespace DBZ_023_Namespace {
  class DBZ_023_Exception : public exception
  {
  public:
    void print();
    
  };

  int DBZ_023_depth01(int value);
  void DBZ_023_depth02();

  void DBZ_023_testFea02();

  void DBZ_023_Exception::print()
  {
    int x = 0;
  }

  int DBZ_023_depth01(int value)
  {
    if(value == 10)
    {
      throw DBZ_023_Exception();
    }

    return value * 2;
  }

  void DBZ_023_depth02()
  {
    int value = 0;
    int* ptr = 0;
    value = DBZ_023_depth01(20);

    value = 0;
    try
    {
      value = DBZ_023_depth01(10);
    }
    catch(DBZ_023_Exception& e)
    {
      int ret = 10000 / value; //@violation DIV_BY_ZERO
    }
  }
}
