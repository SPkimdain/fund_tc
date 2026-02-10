

/* UDS_027 - virtual function call */
class UDS_027_Base {
public:
  virtual void doSomethingVirtual(int* x) {
    x[0] = 100;
  }
};

class UDS_027_Derived : public UDS_027_Base
{
public:
  virtual void doSomethingVirtual(int* x) {
    x[-1] = 10;
  }
};

void UDS_027_function() {
  int p[8] = { 0, };
  UDS_027_Base* inst1 = new UDS_027_Base;
  UDS_027_Base* inst2 = new UDS_027_Derived;

  inst1->doSomethingVirtual(p);
  inst2->doSomethingVirtual(p);	//@violation UNDERRUN.STATIC

  delete inst1;
  delete inst2;
}
