
/* DZMC_007 - Function call, pointer parameter */

void DZMC_007_function1(int arg, int arg2) {
  int ret = 0;
  if(arg2 != 0) {
    ret = 1000 / arg2; /* It's ok. */
  }
  
  if(arg != 0) {
    arg = arg - 10;
  }

  ret = 1000 / arg; //@violation DIV_BY_ZERO.MISSING_CHECK
  return;
}

void DZMC_007_function2(int value) {
  DZMC_007_function1(value, value); 
}
