

/* TUDS_027 - virtual function call */
struct TUDS_027_Struct {
  int i;
  int p[8];
};

class TUDS_027_Base {
public:
  virtual void doSomethingVirtual(int* x) {
    x[5] = 100;
  }
};

class TUDS_027_Derived : public TUDS_027_Base
{
public:
  virtual void doSomethingVirtual(int* x) {
    x[-10] = 10;
  }
};

void TUDS_027_function() {
  TUDS_027_Struct sb;
  TUDS_027_Base* inst1 = new TUDS_027_Base;
  TUDS_027_Base* inst2 = new TUDS_027_Derived;

  inst1->doSomethingVirtual(sb.p);
  inst2->doSomethingVirtual(sb.p);	//@violation TYPE_UNDERRUN.STATIC

  delete inst1;
  delete inst2;
}
