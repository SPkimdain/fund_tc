

/* RL_017 - virtual function call */
class RL_017_Base {
public:
  RL_017_Base(int* param) : value(param) {}

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

class RL_017_Derived : public RL_017_Base {
public:
  RL_017_Derived(int* param, int* param2) : RL_017_Base(param), value2(param2) {}

  virtual int* doSomethingVirtual(int* x) {
    return value2;
  }

private:
  int* value2;
};

int* RL_017_function(int* x, int flag) {
  int local = 1024;
  RL_017_Base* inst1 = new RL_017_Base(x);
  RL_017_Base* inst2 = new RL_017_Derived(x, &local);
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

  return retVal; //@violation RETURN_LOCAL
}

