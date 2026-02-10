
/* UAF_021 - failed dynamic cast. */
namespace UAF_021_Namespace {
  class UAF_021_Base {
  public:
    virtual void function();
  };

  class UAF_021_Derived : public UAF_021_Base {
  public:
    virtual void function();
  };

  void UAF_021_Base::function() {
    int x = 0;
  }

  void UAF_021_Derived::function() {
    int x = 10;
  }

  void UAF_021_function() {
    UAF_021_Base* pb = new UAF_021_Derived;
    UAF_021_Base* pb2 = new UAF_021_Base;

    UAF_021_Derived* pd = dynamic_cast<UAF_021_Derived*>(pb);

    /* Casting failed. pd2 is 0. */
    UAF_021_Derived* pd2 = dynamic_cast<UAF_021_Derived*>(pb2);

    pd->function();
    
    delete pb2; //Possible path.
    
    pb2->function(); //@violation USE_AFTER_FREE
    
    pb2 = 0;
    delete pb;
  }
}
