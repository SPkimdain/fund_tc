//@checker BASE_CLASS_SHOULD_BE_DECLARED_VIRTUAL_ONLY_IN_DIAMOND_HIERARCHY

/* BCSBDVOIDH_001 - basic patterns */

namespace BCSBDVOIDH_001_NS {
  class Base {
  public:
    int val;
  };

  class SA1 : public Base {};
  class SA2 : public Base {};

  class SB1 : public SA1, SA2 {}; //@violation BASE_CLASS_SHOULD_BE_DECLARED_VIRTUAL_ONLY_IN_DIAMOND_HIERARCHY
  class SB2 : public virtual SA2 {}; //It's ok. for SC2.
  class SB3 : public virtual SA2 {}; //It's ok. for SC2.

  class SC1 : public SB1, SB2 {}; //@violation BASE_CLASS_SHOULD_BE_DECLARED_VIRTUAL_ONLY_IN_DIAMOND_HIERARCHY
  class SC2 : public SB2, SB3 {};

  class SD1 : public SC1 {}; //@violation BASE_CLASS_SHOULD_BE_DECLARED_VIRTUAL_ONLY_IN_DIAMOND_HIERARCHY


  class B2 {
  public:
    int val2;
  };

  class SA3 : public virtual B2 {}; //@violation BASE_CLASS_SHOULD_BE_DECLARED_VIRTUAL_ONLY_IN_DIAMOND_HIERARCHY

  class SB4 : public virtual SA3 {}; //@violation BASE_CLASS_SHOULD_BE_DECLARED_VIRTUAL_ONLY_IN_DIAMOND_HIERARCHY




}

