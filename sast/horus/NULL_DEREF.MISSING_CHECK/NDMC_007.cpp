
/* NDMC_007 - Function call, return value */
int* NDMC_007_function1(int* arg, int* arg2, int flag) {
  if(flag > 10) {
    return arg;
  }
  else {
    return arg2;
  }
}

int NDMC_007_function2(int* value, int* value2, int flag) {
  int ret = 0;

  int* ptr = NDMC_007_function1(value, value2, flag);

  if(ptr != 0) {
    ret += *ptr;
  }

  *ptr = 10; //@violation NULL_DEREF.MISSING_CHECK

  return 0;
}
