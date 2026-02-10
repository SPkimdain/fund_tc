
/* ND_057 exception flow */
class ND_057_Base {
  int value;
};

class ND_057_Derived : public ND_057_Base {
};

class ND_057_Derived2 : public ND_057_Base {
};

void ND_057_function1(int* value, ND_057_Base* obj) {
  
  try {
    throw obj;
  }
  catch(ND_057_Derived2* d2) {
    return;
  }
  catch(ND_057_Derived* d) {
    *value = 20;
  }
  catch(ND_057_Base* b) {
    return;
  }
}

void ND_057_function2() {
  ND_057_Base* obj = new ND_057_Derived;
  ND_057_Base* obj2 = new ND_057_Derived2;
  
  ND_057_function1(0, obj2); //It's ok.
  ND_057_function1(0, obj); //@violation NULL_DEREF
  
  delete obj;
  delete obj2;
}

