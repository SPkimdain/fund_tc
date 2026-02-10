

/* DBZ_043 - three dereference  */
void DBZ_043_function1(int ***p) {
  int ret = 1000 / (***p - 100); // DIV_BY_ZERO
}

void DBZ_043_function2() {
  int value = 100;
  int *ptr = &value;
  int **ptr2 = &ptr;
  DBZ_043_function1(&ptr2); //@violation DIV_BY_ZERO
}
