//@checker MISSING_WRAPPER_ON_VARIABLE
void PFM_ERR_API10(int, int);

extern int PfmNumber_API10(int);

void Func_MWRAPOV_001_Function(const char * x) {
  PFM_ERR_API10(0, 0);  //@violation MISSING_WRAPPER_ON_VARIABLE

  return;

}

