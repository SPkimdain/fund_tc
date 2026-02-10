//@checker REUSE_NAME_IN_DIFFERENT_FILE

void RNIDIFF_001_function_bad(int x) { //@global-violation REUSE_NAME_IN_DIFFERENT_FILE 
  int y = 0;
  x++;
  return;  
}


void RNIDIFF_001_function_safe1() {
  int x = 0;
  x++;
  return;
}
