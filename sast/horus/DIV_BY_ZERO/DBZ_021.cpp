
/* DBZ_021 - failed dynamic cast. */
namespace DBZ_021_Namespace {
  class DBZ_021_Base {
  public:
    virtual void function();
  };

  class DBZ_021_Derived : public DBZ_021_Base {
  public:
    virtual void function();
  };

  void DBZ_021_Base::function() {
    int x = 0;
  }

  void DBZ_021_Derived::function() {
    int x = 10;
  }

  void DBZ_021_function() {
    int value = 0;
    DBZ_021_Base* pb = new DBZ_021_Derived;
    DBZ_021_Base* pb2 = new DBZ_021_Base;

    DBZ_021_Derived* pd = dynamic_cast<DBZ_021_Derived*>(pb);

    /* Casting failed. pd2 is 0. */
    DBZ_021_Derived* pd2 = dynamic_cast<DBZ_021_Derived*>(pb2);

    pd->function();
    
    int ret = 1000 / value; // @violation DIV_BY_ZERO
    
    delete pb;
    delete pb2;
  }
}
