

/* OD_027 - virtual function call */
class OD_027_Base {
public:
  virtual void doSomethingVirtual(int* x) {
    x[5] = 100;
  }
};

class OD_027_Derived : public OD_027_Base
{
public:
  virtual void doSomethingVirtual(int* x) {
    x[10] = 10;
  }
};

void OD_027_function() {
  int* p = new int[8];
  if(p == 0) {
    return;
  }
  OD_027_Base* inst1 = new OD_027_Base;
  if(inst1 == 0) {
    delete[] p;
    return;
  }

  OD_027_Base* inst2 = new OD_027_Derived;
  if(inst2 == 0) {
    delete[] p;
    delete inst1;
    return;
  }

  inst1->doSomethingVirtual(p);
  inst2->doSomethingVirtual(p);	//@violation OVERRUN.DYNAMIC

  delete inst1;
  delete inst2;
  delete[] p;
}
