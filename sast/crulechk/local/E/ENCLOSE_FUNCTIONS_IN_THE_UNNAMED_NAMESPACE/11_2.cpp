//@checker ENCLOSE_FUNCTIONS_IN_THE_UNNAMED_NAMESPACE
void foo() {}; //@violation ENCLOSE_FUNCTIONS_IN_THE_UNNAMED_NAMESPACE
void foo1(); //@violation ENCLOSE_FUNCTIONS_IN_THE_UNNAMED_NAMESPACE


namespace {
  void bar() {}; 
  void bar1();
};
