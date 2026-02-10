
/* ND_011 - Complex call expression */
int* ND_011_function1(int value, int* ptr) {
  if(value > 10) {
    return ptr;
  }
  else {
    return 0;
  }
}

void ND_011_function2() {
  int value = 10;
  int value2 = 5;
  int *ptr = &value;
  int *ptr2 = &value2;

  int ret = 0;

  ret = *(ND_011_function1(value + 5, ptr)) +
    *(ND_011_function1(20, ptr2)); // No problem.

  ret = *(ND_011_function1(11, ptr)) + // Ok.
    *(ND_011_function1(value2 + 20, ptr2)) + // Ok.
    *(ND_011_function1(value2, ptr2)); // @violation NULL_DEREF
}
