

/* TOS_027 - virtual function call */
struct TOS_027_Struct {
  int i;
  int p[8];
};

class TOS_027_Base {
public:
  virtual void doSomethingVirtual(int* x) {
    x[5] = 100;
  }
};

class TOS_027_Derived : public TOS_027_Base
{
public:
  virtual void doSomethingVirtual(int* x) {
    x[10] = 10;
  }
};

void TOS_027_function() {
  TOS_027_Struct sb;
  TOS_027_Base* inst1 = new TOS_027_Base;
  TOS_027_Base* inst2 = new TOS_027_Derived;

  inst1->doSomethingVirtual(sb.p);
  inst2->doSomethingVirtual(sb.p);	//@violation TYPE_OVERRUN.STATIC

  delete inst1;
  delete inst2;
}
