//@checker BAD_QUALIFIER.FORBIDDEN.PARAM_PTR
void Fun_BQUALFPP_001_function(const char * a, int b) {  //@violation BAD_QUALIFIER.FORBIDDEN.PARAM_PTR
  int x = 0;
  return;
}

