#include <stdexcept>
#include <iostream>

#include <stdlib.h>
#include <time.h>

/* DBZ_061 - failed dynamic cast(reference). */
using namespace std;

namespace DBZ_061_Namespace {
  class DBZ_061_Base {
  public:
    DBZ_061_Base() : val(10), ch('x') {}
    virtual void function();

    short getVal() { return val; }
    char getCh() { return ch; }

  private:
    short val;
    char ch;
  };

  class DBZ_061_Derived : public DBZ_061_Base {
  public:
    DBZ_061_Derived() : DBZ_061_Base() {}

    virtual void function();
  };

  void DBZ_061_Base::function() {
    cout << "Base call.";
  }

  void DBZ_061_Derived::function() {
    cout << "Derived call.";
  }

  enum class ModOption { PLUS, MINUS };

  class DBZ_061_Class {
  public:
    DBZ_061_Class() {}
    static int initializeVal() {
      srand(time(0));

      int val = rand();
      
      return val;
    }

    static int modifiedVal(int value, ModOption mo = ModOption::MINUS) {
      int modVal = value - 100;
      return adjust(modVal);
    }

    static int adjust(int val) {
      return val < 0 ? 1 : val; //can be zero.
    }

    void DBZ_061_function1(bool flag, int& out) {
      DBZ_061_Base bobj;
      DBZ_061_Derived dobj;
      DBZ_061_Base* pb = 0;
      if(flag == true) {
        pb = &bobj;
        out = 100;
      }
      else {
        pb = &dobj;
        out = 200;
      }

      
	    DBZ_061_Derived& pd = dynamic_cast<DBZ_061_Derived&>(*pb);
      

      pb = 0;

      out += 500;
    }

    int DBZ_061_function2(bool flag)  {
      bool excep = false;
      int value = 1;

      value = DBZ_061_Class::initializeVal();

      try {
        DBZ_061_function1(flag, value);

        value++;
        value++;        
      }
      catch(exception& e) {
        value = DBZ_061_Class::modifiedVal(value);

        cout << e.what();
        excep = true;
      }

      int divend = rand();

      if(divend == 0){
        divend = rand() * 10;
      }

      if(divend > 50000) {
        cout << "Wrong divend.";
        return 1;
      }
      else {
        if(excep == true) {
          cout << divend / value; //@violation DIV_BY_ZERO
        }
        return 0;
      }
    }

  };
}
