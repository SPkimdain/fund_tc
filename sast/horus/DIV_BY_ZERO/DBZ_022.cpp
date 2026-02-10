#include <stdexcept>

/* DBZ_022 - failed dynamic cast(reference). */
using namespace std;

namespace DBZ_022_Namespace {
class DBZ_022_Base {
public:
  virtual void function();
};

class DBZ_022_Derived : public DBZ_022_Base {
public:
  virtual void function();
};

void DBZ_022_Base::function() {
  int x = 0;
}

void DBZ_022_Derived::function()
{
  int x = 0;
}

class DBZ_022_Class {
public:
  DBZ_022_Class() {}
  void DBZ_022_function1(bool flag)
  {
    DBZ_022_Base bobj;
    DBZ_022_Derived dobj;
    
    DBZ_022_Base* pb = 0;
    if(flag == true)
    {
      pb = &bobj;
    }
    else
    {
      pb = &dobj;
    }

    DBZ_022_Derived& pd = dynamic_cast<DBZ_022_Derived&>(*pb);

    pb = 0;
  }

  int DBZ_022_function2(bool flag)
  {
    int value = 0;
    try
    {
      DBZ_022_function1(flag);
    }
    catch(exception& e)
    {
      int ret = 10000 / value; //@violation DIV_BY_ZERO
      e.what();
      return 0;
    }
    return 100;
  }

  void DBZ_021_function3()
  {
    DBZ_022_function2(false);
    DBZ_022_function2(true);
  }  
};
}
