
/* DZMC_008 - Function call, return value */
int DZMC_008_function1(int arg, int flag) {
  if(flag > 10) {
    return 1;
  }
  else {
    return arg;
  }
}

int DZMC_008_function2(int value) {
  int ret = 0;
  int check = DZMC_008_function1(value, 5);

  if(check != 0) {
    ret++;
  }

  ret += 1000 / check; //@violation DIV_BY_ZERO.MISSING_CHECK

  return ret;
}
