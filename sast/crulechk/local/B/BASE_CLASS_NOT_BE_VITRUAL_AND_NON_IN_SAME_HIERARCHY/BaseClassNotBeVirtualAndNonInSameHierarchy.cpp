//@checker BASE_CLASS_NOT_BE_VITRUAL_AND_NON_IN_SAME_HIERARCHY

class A {};
class B1: public virtual A {};
class B2: public virtual A {};
class B3: public  A {};
class C: public B1, B2, B3 {}; //@violation BASE_CLASS_NOT_BE_VITRUAL_AND_NON_IN_SAME_HIERARCHY