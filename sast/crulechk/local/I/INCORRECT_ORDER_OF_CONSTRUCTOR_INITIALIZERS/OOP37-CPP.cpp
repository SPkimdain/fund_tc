// @checker INCORRECT_ORDER_OF_CONSTRUCTOR_INITIALIZERS

class Noncompliant1 {
  int a;
  int b;
 public:
    Noncompliant1() : b(3), a(b+1) {}  // @violation INCORRECT_ORDER_OF_CONSTRUCTOR_INITIALIZERS
};



class Noncompliant2 {
  int a;
  int b;
 public:
  Noncompliant2() : a(b+1), b(3) {}  // @violation INCORRECT_ORDER_OF_CONSTRUCTOR_INITIALIZERS
};



class Compliant {
  int a;
  int b;
 public:
  Compliant() : a(4), b(a-1) {}
};
