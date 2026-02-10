//@checker ASYMMETRIC_OPERATOR_MUST_BE_DEFINED_AS_MEMBER

class ASYNCCCTHR_001_Class {};


ASYNCCCTHR_001_Class& operator+(ASYNCCCTHR_001_Class&, int) {
  ASYNCCCTHR_001_Class c;
  return c;
}

// C& operator[](C&, int) {}  // BUG: "[]" must be defined as member -> compile error
// C& operator()(C&, int) {}  // BUG: "()" must be defined as member -> compile error
// C& operator->(C&) {}  // BUG: "->" must be defined as member -> compile error

ASYNCCCTHR_001_Class& operator*(ASYNCCCTHR_001_Class&) { //@violation ASYMMETRIC_OPERATOR_MUST_BE_DEFINED_AS_MEMBER
  ASYNCCCTHR_001_Class c;
  return c;
} 



class ASYNCCCTHR_001_Class_Derived {
};
