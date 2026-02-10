#include <stdexcept>

/* OD_022 - failed dynamic cast(reference). */
using namespace std;

namespace OD_022_Namespace {
class OD_022_Base {
public:
  virtual void function();
};

class OD_022_Derived : public OD_022_Base {
public:
  virtual void function();
};

void OD_022_Base::function() {
  int x = 0;
}

void OD_022_Derived::function()
{
  int x = 0;
}

class OD_022_Class {
public:
  OD_022_Class() {}

  void OD_022_function1(bool flag) {
    OD_022_Base bobj;
    OD_022_Derived dobj;
    OD_022_Base* pb = 0;
    if(flag == true)
    {
      pb = &bobj;
    }
    else
    {
      pb = &dobj;
    }

    /* exception. */
    OD_022_Derived& pd = dynamic_cast<OD_022_Derived&>(*pb);

    pb = 0;
  }

  int OD_022_function2(bool flag)
  {
    try
    {
      OD_022_function1(flag);
    }
    catch(exception& e)
    {
      int* p = new int[3];
      if(p == 0) {
        return 0;
      }
      p[4] = 10; //@violation OVERRUN.DYNAMIC
      e.what();
      delete[] p;
      return 0;
    }
    return 100;
  }

  void OD_022_function3()
  {
    OD_022_function2(false);
    OD_022_function2(true);
  }

};
}
