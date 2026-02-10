//@checker SYMMETRIC_OPERATOR_SHOULD_BE_DEFINED_AS_FRIEND

class SYMOMBDAM_001_Class {};


SYMOMBDAM_001_Class& operator+(SYMOMBDAM_001_Class&, int) {}

// C& operator[](C&, int) {}  // BUG: "[]" must be defined as member -> compile error
// C& operator()(C&, int) {}  // BUG: "()" must be defined as member -> compile error
// C& operator->(C&) {}  // BUG: "->" must be defined as member -> compile error

SYMOMBDAM_001_Class& operator*(SYMOMBDAM_001_Class&) {}  



class SYMOMBDAM_001_Derived {
  SYMOMBDAM_001_Derived& operator*(SYMOMBDAM_001_Derived&);  //@violation SYMMETRIC_OPERATOR_SHOULD_BE_DEFINED_AS_FRIEND
  SYMOMBDAM_001_Derived& operator^(SYMOMBDAM_001_Derived&);  //@violation SYMMETRIC_OPERATOR_SHOULD_BE_DEFINED_AS_FRIEND
  SYMOMBDAM_001_Derived& operator-(SYMOMBDAM_001_Derived&);
};
