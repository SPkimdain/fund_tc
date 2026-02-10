#include <stdexcept>

/* UAF_022 - failed dynamic cast(reference). */
using namespace std;

namespace UAF_022_Namespace {
class UAF_022_Base {
public:
  virtual void function();
};

class UAF_022_Derived : public UAF_022_Base {
public:
  virtual void function();
};

void UAF_022_Base::function() {
  int x = 0;
}

void UAF_022_Derived::function()
{
  int x = 0;
}

class UAF_022_Class {
public:
  UAF_022_Class()  {}

  void UAF_022_function1(bool flag)
  {
    UAF_022_Base bobj;
    UAF_022_Derived dobj;
    UAF_022_Base* pb = 0;
    if(flag == true)
    {
      pb = &bobj;
    }
    else
    {
      pb = &dobj;
    }

    UAF_022_Derived& pd = dynamic_cast<UAF_022_Derived&>(*pb);

    pb = 0;
  }

  int UAF_022_function2(bool flag)
  {
    int* ptr = new int();
    try
    {
      delete ptr;
      UAF_022_function1(flag);
      ptr = new int(5);
    }
    catch(exception& e)
    {
      *ptr = 10; //@violation USE_AFTER_FREE
      e.what();
      return 0;
    }
    delete ptr;
    return 100;
  }

  void UAF_021_function3()
  {
    UAF_022_function2(false);
    UAF_022_function2(true);
  }

};
}
