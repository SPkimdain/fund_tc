
/* DBZ_008 - Function call, return value */
int DBZ_008_function1(int arg, int flag) {
  if(flag > 10) {
    return arg;
  }
  else {
    return 0;
  }
}

void DBZ_008_function2() {
  int value = 10;
  int ptr = DBZ_008_function1(value, 5);

  int ret = 1000 / (10 - value); //@violation DIV_BY_ZERO
}
