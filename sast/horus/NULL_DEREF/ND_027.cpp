

/* ND_027 - virtual function call */
class ND_027_Base {
public:
  virtual void doSomethingVirtual(int* x) {
    if(x == 0) {
      int y = 0;
    }
  }
};

class ND_027_Derived : public ND_027_Base
{
public:
  virtual void doSomethingVirtual(int* x) {
    *x = 10; 
  }
};

void ND_027_function() {
  ND_027_Base* inst1 = new ND_027_Base;
  ND_027_Base* inst2 = new ND_027_Derived;

  inst1->doSomethingVirtual(0);
  inst2->doSomethingVirtual(0);//@violation NULL_DEREF

  delete inst1;
  delete inst2;
}
