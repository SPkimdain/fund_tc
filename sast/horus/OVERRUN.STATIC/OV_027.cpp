

/* OV_027 - virtual function call */
class OV_027_Base {
public:
  virtual void doSomethingVirtual(int* x) {
    x[5] = 100;
  }
};

class OV_027_Derived : public OV_027_Base
{
public:
  virtual void doSomethingVirtual(int* x) {
    x[10] = 10;
  }
};

void OV_027_function() {
  int p[8] = { 0, };
  OV_027_Base* inst1 = new OV_027_Base;
  OV_027_Base* inst2 = new OV_027_Derived;

  inst1->doSomethingVirtual(p);
  inst2->doSomethingVirtual(p);	//@violation OVERRUN.STATIC

  delete inst1;
  delete inst2;
}
