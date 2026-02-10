
/* UDS_021 - failed dynamic cast. */
namespace UDS_021_Namespace {
  class UDS_021_Base {
  public:
    virtual void function();
  };

  class UDS_021_Derived : public UDS_021_Base {
  public:
    virtual void function();
  };

  void UDS_021_Base::function() {
    int x = 0;
  }

  void UDS_021_Derived::function() {
    int x = 10;
  }

  void UDS_021_function() {
    int p[2] = { 0, };
    UDS_021_Base* pb = new UDS_021_Derived;
    UDS_021_Base* pb2 = new UDS_021_Base;

    UDS_021_Derived* pd = dynamic_cast<UDS_021_Derived*>(pb);

    /* Casting failed. pd2 is 0. */
    UDS_021_Derived* pd2 = dynamic_cast<UDS_021_Derived*>(pb2);

    pd->function();
    int ret = p[-3]; //@violation UNDERRUN.STATIC
    
    delete pb;
    delete pb2;
  }
}
