
/* ANM_002 - simple case2 */

struct ANM_002_Base {
  virtual ~ANM_002_Base() {}
};
struct ANM_002_Derived : ANM_002_Base {
  virtual ~ANM_002_Derived() {}
  virtual void g() {
    /* ... */
  }
};

void ANM_002_memptr(ANM_002_Derived * ptr) {
  void(ANM_002_Derived::*gptr)(); //Uninit.


  (ptr->*gptr)(); //@violation ACCESS_NONEXISTENT_MEMBERS
}

void ANM_002_memptr_safe(ANM_002_Derived * ptr) {
  void(ANM_002_Derived::*gptr2)() = &ANM_002_Derived::g;

  (ptr->*gptr2)(); //It's ok.
}
