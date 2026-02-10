
/* ND_021 - failed dynamic cast. */
namespace ND_021_Namespace {
  class ND_021_Base {
  public:
    virtual void function();
  protected:
    int value;
  };

  class ND_021_Derived : public ND_021_Base {
  public:
    virtual void function();
  };

  void ND_021_Base::function() {
    value = 0;
  }

  void ND_021_Derived::function() {
    value = 10;
  }

  void ND_021_function() {
    ND_021_Base* pb = new ND_021_Derived;
    ND_021_Base* pb2 = new ND_021_Base;

    ND_021_Derived* pd = dynamic_cast<ND_021_Derived*>(pb);

    /* Casting failed. pd2 is 0. */
    ND_021_Derived* pd2 = dynamic_cast<ND_021_Derived*>(pb2);

    pd->function();
    pd2->function(); // @violation NULL_DEREF

    delete pb;
    delete pb2;
  }
}
