
/* DBZ_007 - Function call, pointer parameter */

void DBZ_007_function1(int arg, int arg2) {
  int ret = 0;
  if(arg2 != 0) {
    ret = 1000 / arg2; /* It's ok. */
  }
  arg = arg - 10;
  ret = 1000 / arg; // DIV_BY_ZERO
  return;
}

void DBZ_007_function2() {
  int value = 10;
  DBZ_007_function1(value, value); //@violation DIV_BY_ZERO
}
