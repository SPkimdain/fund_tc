#include <stdexcept>

/* ND_022 - failed dynamic cast(reference). */
using namespace std;

namespace ND_022_Namespace {
class ND_022_Base {
public:
  virtual void function();
};

class ND_022_Derived : public ND_022_Base {
public:
  virtual void function();
};

void ND_022_Base::function() {
  int x = 0;
}

void ND_022_Derived::function()
{
  int x = 0;
}

class ND_022_Class {
public:
  ND_022_Class() {}
  void ND_022_function1(bool flag)
  {
    ND_022_Base bobj;
    ND_022_Derived dobj;
    ND_022_Base* pb = 0;
    if(flag == true)
    {
      pb = &bobj;
    }
    else
    {
      pb = &dobj;
    }

    /* exception. */
    ND_022_Derived& pd = dynamic_cast<ND_022_Derived&>(*pb);

    pb = 0;
  }

  int ND_022_function2(bool flag)
  {
    try
    {
      ND_022_function1(flag);
    }
    catch(exception& e)
    {
      int* ptr = 0;
      *ptr = 10; //@violation NULL_DEREF
      e.what();
      return 0;
    }
    return 100;
  }

  void ND_021_function3()
  {
    ND_022_function2(false);
    ND_022_function2(true);
  }
};
}
