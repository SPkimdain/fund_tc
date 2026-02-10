
/* DBZ_011 - Complex call expression */
int DBZ_011_function1(int value, int value2) {
  if(value > 0) {
    return value2;
  }
  else {
    return 0;
  }
}

void DBZ_011_function2() {
  int value = 10;
  int value2 = 5;
  int *ptr = &value;
  int *ptr2 = &value2;

  int ret = 0;

  ret = (100 / (DBZ_011_function1(value + 5, *ptr))) +
    (200 / (DBZ_011_function1(20, *ptr2))); // No problem.

  ret = (100 / (DBZ_011_function1(11, *ptr))) + // Ok.
    (200 / (DBZ_011_function1(value2 + 20, *ptr2))) + // Ok.
    (300 / (DBZ_011_function1(-1, *ptr2))); // @violation DIV_BY_ZERO
}

