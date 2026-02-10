

/* UN_027 - virtual function call */
class UN_027_Base {
public:
  virtual void doSomethingVirtual(int* x) {
    *x = 10;
  }
};

class UN_027_Derived : public UN_027_Base
{
public:
  virtual void doSomethingVirtual(int* x) {
    int ret = *x; // UNINIT
  }
};

void UN_027_function() {
  int x;
  int y;
  UN_027_Base* inst1 = new UN_027_Base;
  UN_027_Base* inst2 = new UN_027_Derived;

  inst1->doSomethingVirtual(&x);
  inst2->doSomethingVirtual(&y);//@violation UNINIT

  delete inst1;
  delete inst2;
}
