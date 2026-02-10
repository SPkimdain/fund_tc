#include <stdexcept>

/* TUDS_022 - failed dynamic cast(reference). */
using namespace std;

namespace TUDS_022_Namespace {
struct TUDS_022_Struct {
  int i;
  char c;
  long l;
  int p[3];
};

class TUDS_022_Base {
public:
  virtual void function();
};

class TUDS_022_Derived : public TUDS_022_Base {
public:
  virtual void function();
};

void TUDS_022_Base::function() {
  int x = 0;
}

void TUDS_022_Derived::function()
{
  int x = 0;
}

class TUDS_022_Class {
public:
  TUDS_022_Class() {}
  void TUDS_022_function1(bool flag)
  {
    TUDS_022_Base bobj;
    TUDS_022_Derived dobj;
    TUDS_022_Base* pb = 0;
    if(flag == true)
    {
      pb = &bobj;
    }
    else
    {
      pb = &dobj;
    }

    /* exception */
    TUDS_022_Derived& pd = dynamic_cast<TUDS_022_Derived&>(*pb);

    pb = 0;
  }

  int TUDS_022_function2(bool flag)
  {
    try
    {
      TUDS_022_function1(flag);
    }
    catch(exception& e)
    {
      TUDS_022_Struct sb;
      sb.p[-4] = 10; //@violation TYPE_UNDERRUN.STATIC
      e.what();
      return 0;
    }
    return 100;
  }

  void TUDS_022_function3()
  {
    TUDS_022_function2(false);
    TUDS_022_function2(true);
  }


};
}
