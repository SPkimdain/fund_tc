//@checker REUSE_NAME_IN_DIFFERENT_FILE

int RNIDIFF_001_function_bad(int x) { //@global-violation REUSE_NAME_IN_DIFFERENT_FILE 
  int y = 0;
  x++;
  return x;  
}


int RNIDIFF_002_function_safe2() {
  int y = 0;
  y += 10;
  return y;
}
