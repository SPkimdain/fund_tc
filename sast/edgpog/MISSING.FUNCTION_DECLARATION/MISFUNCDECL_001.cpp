//@checker MISSING.FUNCTION_DECLARATION

int MISFUNCDECL_001_function(int x) {
  int ret = missingFuncDecl(x); //@violation MISSING.FUNCTION_DECLARATION
    
  return ret;
}
