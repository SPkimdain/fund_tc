
/* ANM_001 - simple case1 */

struct ANM_001_Base {
  virtual ~ANM_001_Base() {}
};
struct ANM_001_Derived : ANM_001_Base {
  virtual ~ANM_001_Derived() {}
  virtual void ggg() {
    int x = 0;
    x++;
  }
};


void ANM_001_function1() {
  ANM_001_Base * b = new ANM_001_Base;
  
  void(ANM_001_Base:: * gptr)() = static_cast<void(ANM_001_Base:: *)()> (&ANM_001_Derived::ggg);
  (b->*gptr)(); //@violation ACCESS_NONEXISTENT_MEMBERS
  delete b;
}

void ANM_001_function2() {
  ANM_001_Derived* d  = new ANM_001_Derived;
  d->ggg();

  void(ANM_001_Derived:: * gptr)() = static_cast<void(ANM_001_Derived:: *)()> (&ANM_001_Derived::ggg);
  (d->*gptr)(); //It's ok.
  delete d;
}

