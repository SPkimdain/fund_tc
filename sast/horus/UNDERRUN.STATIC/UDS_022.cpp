#include <stdexcept>

/* UDS_022 - failed dynamic cast(reference). */
using namespace std;

namespace UDS_022_Namespace {
class UDS_022_Base {
public:
  virtual void function();
};

class UDS_022_Derived : public UDS_022_Base {
public:
  virtual void function();
};

void UDS_022_Base::function() {
  int x = 0;
}

void UDS_022_Derived::function()
{
  int x = 0;
}

class UDS_022_Class {
public:
  UDS_022_Class() {}

  void UDS_022_function1(bool flag)
  {
    UDS_022_Base bobj;
    UDS_022_Derived dobj;
    UDS_022_Base* pb = 0;
    if(flag == true)
    {
      pb = &bobj;
    }
    else
    {
      pb = &dobj;
    }

    UDS_022_Derived& pd = dynamic_cast<UDS_022_Derived&>(*pb);

    pb = 0;
  }

  int UDS_022_function2(bool flag)
  {
    try
    {
      UDS_022_function1(flag);
    }
    catch(exception& e)
    {
      int p[3] = { 0, };
      p[-4] = 10; //@violation UNDERRUN.STATIC
      e.what();
      return 0;
    }
    return 100;
  }

  void UDS_022_function3()
  {
    UDS_022_function2(false);
    UDS_022_function2(true);
  }


};
}
