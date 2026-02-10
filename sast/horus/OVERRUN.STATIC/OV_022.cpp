#include <stdexcept>

/* OV_022 - failed dynamic cast(reference). */
using namespace std;

namespace OV_022_Namespace {
class OV_022_Base {
public:
  virtual void function();
};

class OV_022_Derived : public OV_022_Base {
public:
  virtual void function();
};

void OV_022_Base::function() {
  int x = 0;
}

void OV_022_Derived::function()
{
  int x = 0;
}

class OV_022_Class {
public:
  OV_022_Class() {}

  void OV_022_function1(bool flag)
  {
    OV_022_Base bobj;
    OV_022_Derived dobj;
    OV_022_Base* pb = 0;
    if(flag == true)
    {
      pb = &bobj;
    }
    else
    {
      pb = &dobj;
    }

    /* exception. */
    OV_022_Derived& pd = dynamic_cast<OV_022_Derived&>(*pb);

    pb = 0;
  }

  int OV_022_function2(bool flag)
  {
    try
    {
      OV_022_function1(flag);
    }
    catch(exception& e)
    {
      int p[3] = { 0, };
      p[4] = 10; //@violation OVERRUN.STATIC
      e.what();
      return 0;
    }
    return 100;
  }

  void OV_022_function3()
  {
    OV_022_function2(false);
    OV_022_function2(true);
  }


};
}
