
/* UDD_021 - failed dynamic cast. */
namespace UDD_021_Namespace {
  class UDD_021_Base {
  public:
    virtual void function();
  };

  class UDD_021_Derived : public UDD_021_Base {
  public:
    virtual void function();
  };

  void UDD_021_Base::function() {
    int x = 0;
  }

  void UDD_021_Derived::function() {
    int x = 10;
  }

  void UDD_021_function() {
    int* p = new int[2];
    if(p == 0) {
      return;
    }
    UDD_021_Base* pb = new UDD_021_Derived;
    if(pb == 0) {
      delete[] p;
      return;
    }

    UDD_021_Base* pb2 = new UDD_021_Base;    
    if(pb2 == 0) {
      delete[] p;
      delete pb;
      return;
    }

    UDD_021_Derived* pd = dynamic_cast<UDD_021_Derived*>(pb);

    /* Casting failed. pd2 is 0. */
    UDD_021_Derived* pd2 = dynamic_cast<UDD_021_Derived*>(pb2);

    pd->function();
    
    int ret = p[-3]; //@violation UNDERRUN.DYNAMIC
    

    delete pb;
    delete pb2;
    delete[] p;
  }
}
