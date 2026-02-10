#pragma warning(disable : 4700)

/* UN_021 - failed dynamic cast. */
namespace UN_021_Namespace {
  class UN_021_Base {
  public:
    virtual void function();
  };

  class UN_021_Derived : public UN_021_Base {
  public:
    virtual void function();
  };

  void UN_021_Base::function() {
    int x = 0;
  }

  void UN_021_Derived::function() {
    int x = 10;
  }

  void UN_021_function() {
    UN_021_Base* pb = new UN_021_Derived;
    UN_021_Base* pb2 = new UN_021_Base;
    int x;
    int x2;

    UN_021_Derived* pd = dynamic_cast<UN_021_Derived*>(pb);

    /* Casting failed. pd2 is 0. */
    UN_021_Derived* pd2 = dynamic_cast<UN_021_Derived*>(pb2);

    pd->function();
    
    x2 = x; //@violation UNINIT

    delete pb;
    delete pb2;
  }
}
