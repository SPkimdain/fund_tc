
/* OV_021 - failed dynamic cast. */
namespace OV_021_Namespace {
  class OV_021_Base {
  public:
    virtual void function();
  };

  class OV_021_Derived : public OV_021_Base {
  public:
    virtual void function();
  };

  void OV_021_Base::function() {
    int x = 0;
  }

  void OV_021_Derived::function() {
    int x = 10;
  }

  void OV_021_function() {
    int p[2] = { 0, };
    OV_021_Base* pb = new OV_021_Derived;
    OV_021_Base* pb2 = new OV_021_Base;

    OV_021_Derived* pd = dynamic_cast<OV_021_Derived*>(pb);

    /* Casting failed. pd2 is 0. */
    OV_021_Derived* pd2 = dynamic_cast<OV_021_Derived*>(pb2);

    pd->function();
    
    int ret = p[3]; //@violation OVERRUN.STATIC

    delete pb;
    delete pb2;
  }
}
