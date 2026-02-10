//@checker USE_CONST_WHENEVER_POSSIBLE

int UCWEP_007_function(int *const p) { //@violation USE_CONST_WHENEVER_POSSIBLE
  return *p;
}

int UCWEP_007_function2(const int *p) { //It's ok.
  const int x = 10;
  p = &x;
  return 5;
}

int UCWEP_007_function3(int *const p) { //It's ok.
  *p = 20;
  return *p;
}
