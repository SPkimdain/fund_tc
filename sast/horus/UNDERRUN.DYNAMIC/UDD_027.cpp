

/* UDD_027 - virtual function call */
class UDD_027_Base {
public:
  virtual void doSomethingVirtual(int* x) {
    x[5] = 100;
  }
};

class UDD_027_Derived : public UDD_027_Base
{
public:
  virtual void doSomethingVirtual(int* x) {
    x[-10] = 10;
  }
};

void UDD_027_function() {
  int* p = new int[8];
  if(p == 0) {
    return;
  }
  UDD_027_Base* inst1 = new UDD_027_Base;
  if(inst1 == 0) {
    delete[] p;
    return;
  }

  UDD_027_Base* inst2 = new UDD_027_Derived;
  if(inst2 == 0) {
    delete[] p;
    delete inst1;
    return;
  }

  inst1->doSomethingVirtual(p);
  inst2->doSomethingVirtual(p);	//@violation UNDERRUN.DYNAMIC

  delete inst1;
  delete inst2;
  delete[] p;
}
