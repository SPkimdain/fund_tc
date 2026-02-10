
/* ND_008 - Function call, return value */
int* ND_008_function1(int* arg, int flag) {
  if(flag > 10) {
    return arg;
  }
  else {
    return 0;
  }
}

void ND_008_function2() {
  int value = 10;
  int* ptr = ND_008_function1(&value, 5);

  *ptr = 10; //@violation NULL_DEREF
}
