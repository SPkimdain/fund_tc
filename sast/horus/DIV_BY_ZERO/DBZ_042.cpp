
/* DBZ_042 - two dereference */
void DBZ_042_function1(int** p) {
  int ret = 1000 / (**p - 10); //DIV_BY_ZERO
}

void DBZ_042_function2() {
  int value = 10;
  int *ptr = &value;
  DBZ_042_function1(&ptr); //@violation DIV_BY_ZERO
}
