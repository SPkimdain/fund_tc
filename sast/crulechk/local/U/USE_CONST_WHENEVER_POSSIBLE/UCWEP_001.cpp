//@checker USE_CONST_WHENEVER_POSSIBLE

int UCWEP_001_function(int *p
  ) { //@violation USE_CONST_WHENEVER_POSSIBLE
  return *p;
}

int UCWEP_001_function2(int *const p) { //It's ok.
  *p = 10;
  return *p;
}


int UCWEP_001_function3(const int *p) { //It's ok.
  const int x = 10;
  p = &x;
  return 5;
}

int UCWEP_001_function4(int *p) { //It's ok.
  *p = 10;
  p = 0;
  return 1;
}

int UCWEP_001_function5(const int *const p) { //It's ok.
  return *p;
}
