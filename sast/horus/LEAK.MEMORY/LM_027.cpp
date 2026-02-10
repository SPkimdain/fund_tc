

/* LM_027 - virtual function call */
class LM_027_Base {
public:
  LM_027_Base() : value(0) {}
  virtual ~LM_027_Base() {
    if(value != 0){
      delete value;
    }
  }
  virtual void doSomethingVirtual(int* x) {
    value = x;
  }
private:
  int* value;
};

class LM_027_Derived : public LM_027_Base
{
public:
  LM_027_Derived() : LM_027_Base(), value2(0) {}
  ~LM_027_Derived() {
    //value2 is leaked.
  }
  virtual void doSomethingVirtual(int* x) {
    value2 = x;
  }
private:
  int* value2;
};

void LM_027_function() {
  LM_027_Base* inst1 = new LM_027_Base;
  LM_027_Base* inst2 = new LM_027_Derived;

  inst1->doSomethingVirtual(new int(10));
  inst2->doSomethingVirtual(new int(5));

  delete inst1;
  delete inst2; 
}//@violation LEAK.MEMORY
