

/* PPTL_012 - virtual function call */
class PPTL_012_Base {
public:
  PPTL_012_Base(int* param) : value(param) {}

  virtual int* doSomethingVirtual(int* x) {
    if(x != 0) {
      return value;
    }
    else {
      return 0;
    }
  }
private:
  int* value;
};

class PPTL_012_Derived : public PPTL_012_Base {
public:
  PPTL_012_Derived(int* param, int* param2) : PPTL_012_Base(param), value2(param2) {}

  virtual int* doSomethingVirtual(int* x) {
    return value2;
  }

private:
  int* value2;
};

void PPTL_012_function(int* x, int flag, int** out) {
  int local = 1024;
  PPTL_012_Base* inst1 = new PPTL_012_Base(x);
  PPTL_012_Base* inst2 = new PPTL_012_Derived(x, &local);
  int* retVal = 0;
  int y = 10;

  switch(flag) {
  case 1:
    retVal = inst1->doSomethingVirtual(0); //retVal = 0 ;
    break;
  case 2:
    retVal = inst2->doSomethingVirtual(0); //retVal = local address ;
    break;
  case 3:
    retVal = inst1->doSomethingVirtual(&y); //retVal = x ;
    break;
  }

  delete inst1;
  delete inst2;

  *out = retVal; //@violation PARAMETER_POINTER_TO_LOCAL
}

