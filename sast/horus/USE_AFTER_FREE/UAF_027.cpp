

/* UAF_027 - virtual function call */
class UAF_027_Base {
public:
  virtual void doSomethingVirtual(int* x) {
    (*x)++;
  }
};

class UAF_027_Derived : public UAF_027_Base
{
public:
  virtual void doSomethingVirtual(int* x) {
    delete x;
  }
};

void UAF_027_function() {
  UAF_027_Base* inst1 = new UAF_027_Base;
  UAF_027_Base* inst2 = new UAF_027_Derived;
  int* x = new int(10);
  int* y = new int(20);

  inst1->doSomethingVirtual(x);
  inst2->doSomethingVirtual(y);

  (*x)++; //It's ok.
  (*y)++; //@violation USE_AFTER_FREE

  delete x;
  delete inst1;
  delete inst2;
}
