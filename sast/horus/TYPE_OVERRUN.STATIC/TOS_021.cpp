
/* TOS_021 - failed dynamic cast. */
struct TOS_021_Struct {
  int i;
  char c;
  long l;
  int p[2];
};

namespace TOS_021_Namespace {
  class TOS_021_Base {
  public:
    virtual void function();
  };

  class TOS_021_Derived : public TOS_021_Base {
  public:
    virtual void function();
  };

  void TOS_021_Base::function() {
    int x = 0;
  }

  void TOS_021_Derived::function() {
    int x = 10;
  }

  void TOS_021_function() {
    TOS_021_Struct sb;
    TOS_021_Base* pb = new TOS_021_Derived;
    TOS_021_Base* pb2 = new TOS_021_Base;

    TOS_021_Derived* pd = dynamic_cast<TOS_021_Derived*>(pb);

    /* Casting failed. pd2 is 0. */
    TOS_021_Derived* pd2 = dynamic_cast<TOS_021_Derived*>(pb2);

    pd->function();
    
    int ret = sb.p[3]; //@violation TYPE_OVERRUN.STATIC
    
    delete pb;
    delete pb2;
  }
}
