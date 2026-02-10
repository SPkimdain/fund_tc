#include <stdexcept>

/* TOS_022 - failed dynamic cast(reference). */
using namespace std;

namespace TOS_022_Namespace {
struct TOS_022_Struct {
  int i;
  char c;
  long l;
  int p[3];
};

class TOS_022_Base {
public:
  virtual void function();
};

class TOS_022_Derived : public TOS_022_Base {
public:
  virtual void function();
};

void TOS_022_Base::function() {
  int x = 0;
}

void TOS_022_Derived::function()
{
  int x = 0;
}

class TOS_022_Class {
public:
  TOS_022_Class() {}
  void TOS_022_function1(bool flag)
  {
    TOS_022_Base bobj;
    TOS_022_Derived dobj;
    TOS_022_Base* pb = 0;
    if(flag == true)
    {
      pb = &bobj;
    }
    else
    {
      pb = &dobj;
    }

    TOS_022_Derived& pd = dynamic_cast<TOS_022_Derived&>(*pb);

    pb = 0;
  }

  int TOS_022_function2(bool flag)
  {
    try
    {
      TOS_022_function1(flag);
    }
    catch(exception& e)
    {
      TOS_022_Struct sb;
      sb.p[4] = 10; //@violation TYPE_OVERRUN.STATIC
      e.what();
      return 0;
    }
    return 100;
  }

  void TOS_022_function3()
  {
    TOS_022_function2(false);
    TOS_022_function2(true);
  }


};
}
