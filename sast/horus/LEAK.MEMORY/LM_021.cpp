
/* LM_021 - failed dynamic cast. */
namespace LM_021_Namespace {
  class LM_021_Base {
  public:
    virtual void function();
  };

  class LM_021_Derived : public LM_021_Base {
  public:
    virtual void function();
  };

  void LM_021_Base::function() {
    int x = 0;
  }

  void LM_021_Derived::function() {
    int x = 10;
  }

  void LM_021_function() {
    LM_021_Base* pb = new LM_021_Derived;
    LM_021_Base* pb2 = new LM_021_Base;

    LM_021_Derived* pd = dynamic_cast<LM_021_Derived*>(pb);

    /* Casting failed. pd2 is 0. */
    LM_021_Derived* pd2 = dynamic_cast<LM_021_Derived*>(pb2);

    pd->function();
    
    delete pb;
	//pb2 is leaked.
	return; 
    
    delete pb2;	
    return;
  }	//@violation LEAK.MEMORY
}
