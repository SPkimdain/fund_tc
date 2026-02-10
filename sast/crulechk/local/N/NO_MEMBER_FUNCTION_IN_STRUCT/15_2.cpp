//@checker NO_MEMBER_FUNCTION_IN_STRUCT
struct A {
  void foo() {};	//@violation NO_MEMBER_FUNCTION_IN_STRUCT
};


struct B {
private:
  int a;	//@violation NO_MEMBER_FUNCTION_IN_STRUCT
};


struct C {
  int a;
private:
};



struct D {
public:
  int a;
};
