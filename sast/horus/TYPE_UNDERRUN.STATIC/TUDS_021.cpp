
/* TUDS_021 - failed dynamic cast. */
struct TUDS_021_Struct {
  int i;
  char c;
  long l;
  int p[2];
};

namespace TUDS_021_Namespace {
  class TUDS_021_Base {
  public:
    virtual void function();
  };

  class TUDS_021_Derived : public TUDS_021_Base {
  public:
    virtual void function();
  };

  void TUDS_021_Base::function() {
    int x = 0;
  }

  void TUDS_021_Derived::function() {
    int x = 10;
  }

  void TUDS_021_function() {
    TUDS_021_Struct sb;
    TUDS_021_Base* pb = new TUDS_021_Derived;
    TUDS_021_Base* pb2 = new TUDS_021_Base;

    TUDS_021_Derived* pd = dynamic_cast<TUDS_021_Derived*>(pb);

    /* Casting failed. pd2 is 0. */
    TUDS_021_Derived* pd2 = dynamic_cast<TUDS_021_Derived*>(pb2);

    pd->function();
    
    int ret = sb.p[-3]; //@violation TYPE_UNDERRUN.STATIC
    
    delete pb;
    delete pb2;
  }
}
