#pragma warning(disable : 4700)

#include <stdexcept>

/* UN_022 - failed dynamic cast(reference). */
using namespace std;

namespace UN_022_Namespace {
class UN_022_Base {
public:
  virtual void function();
};

class UN_022_Derived : public UN_022_Base {
public:
  virtual void function();
};

void UN_022_Base::function() {
  int x = 0;
}

void UN_022_Derived::function()
{
  int x = 0;
}


class UN_022_Class {
public:
  UN_022_Class() {}

  void UN_022_function1(bool flag)
  {
    UN_022_Base bobj;
    UN_022_Derived dobj;
    UN_022_Base* pb = 0;
    if(flag == true)
    {
      pb = &bobj;
    }
    else
    {
      pb = &dobj;
    }

    /* exception. */
    UN_022_Derived& pd = dynamic_cast<UN_022_Derived&>(*pb);

  }

  int UN_022_function2(bool flag, char* x)
  {
    char p;
    try
    {
      UN_022_function1(flag);
      p = 0;
    }
    catch(exception& e)
    {
      *x = p; //@violation UNINIT
      e.what();
      return 0;
    }
    return 100;
  }

  void UN_021_function3()
  {
    char x = 'a';
    UN_022_function2(false, &x);
    UN_022_function2(true, &x);
  }


};
}
