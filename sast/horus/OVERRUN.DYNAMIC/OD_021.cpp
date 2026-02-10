
/* OD_021 - failed dynamic cast. */
namespace OD_021_Namespace {
  class OD_021_Base {
  public:
    virtual void function();
  };

  class OD_021_Derived : public OD_021_Base {
  public:
    virtual void function();
  };

  void OD_021_Base::function() {
    int x = 0;
  }

  void OD_021_Derived::function() {
    int x = 10;
  }

  void OD_021_function() {
    int* p = new int[2];
    if(p == 0) {
      return;
    }
    OD_021_Base* pb = new OD_021_Derived;
    if(pb == 0) {
      delete[] p;
      return;
    }

    OD_021_Base* pb2 = new OD_021_Base;    
    if(pb2 == 0) {
      delete[] p;
      delete pb;
      return;
    }

    OD_021_Derived* pd = dynamic_cast<OD_021_Derived*>(pb);

    /* Casting failed. pd2 is 0. */
    OD_021_Derived* pd2 = dynamic_cast<OD_021_Derived*>(pb2);

    pd->function();

    int ret = p[3]; //@violation OVERRUN.DYNAMIC

    delete pb;
    delete pb2;
    delete[] p;
  }
}
