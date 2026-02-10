
/* ANM_003 - simple case2 */

struct ANM_003_Base {
  virtual ~ANM_003_Base() {}
};
struct ANM_003_Derived : ANM_003_Base {
  virtual ~ANM_003_Derived() {}
  virtual void g() {
    /* ... */
  }
};

void ANM_003_memptr(ANM_003_Derived * ptr) {
  void(ANM_003_Derived::*gptr)() = nullptr;

  (ptr->*gptr)();  //@violation ACCESS_NONEXISTENT_MEMBERS
}

void ANM_003_memptr_safe(ANM_003_Derived * ptr) {
  void(ANM_003_Derived::*gptr2)() = &ANM_003_Derived::g;

  (ptr->*gptr2)(); //It's ok.
}

