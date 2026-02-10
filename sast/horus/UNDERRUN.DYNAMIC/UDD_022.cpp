#include <stdexcept>

/* UDD_022 - failed dynamic cast(reference). */
using namespace std;

namespace UDD_022_Namespace {
class UDD_022_Base {
public:
  virtual void function();
};

class UDD_022_Derived : public UDD_022_Base {
public:
  virtual void function();
};

void UDD_022_Base::function() {
  int x = 0;
}

void UDD_022_Derived::function()
{
  int x = 0;
}


class UDD_022_Class {
public:
  UDD_022_Class()  {}

  void UDD_022_function1(bool flag) {
    UDD_022_Base bobj;
    UDD_022_Derived dobj;
    UDD_022_Base* pb = 0;
    if(flag == true)
    {
      pb = &bobj;
    }
    else
    {
      pb = &dobj;
    }

    UDD_022_Derived& pd = dynamic_cast<UDD_022_Derived&>(*pb);

    pb = 0;
  }

  int UDD_022_function2(bool flag)
  {
    try
    {
      UDD_022_function1(flag);
    }
    catch(exception& e)
    {
      int* p = new int[3];
      if(p == 0) {
        return 0;
      }
      p[-4] = 10; //@violation UNDERRUN.DYNAMIC
      e.what();
      delete[] p;
      return 0;
    }
    return 100;
  }

  void UDD_022_function3()
  {
    UDD_022_function2(false);
    UDD_022_function2(true);
  }


};
}
