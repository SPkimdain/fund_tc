//@checker SYNTACTICALLY_AMBIGUOUS_DECLARATIONS

struct SYNAMBDECL_Struct {
  SYNAMBDECL_Struct() {
    //...
  }
};

void SYNAMBDECL_001_function() {
  SYNAMBDECL_Struct sad(); //@violation SYNTACTICALLY_AMBIGUOUS_DECLARATIONS
  
  SYNAMBDECL_Struct sad2; //It's ok.
  
  SYNAMBDECL_Struct sad3{}; //It's ok.

  auto&& lambda = [](int x) {
    return x + 10;
  }; //It's ok.
}
