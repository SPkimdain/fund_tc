
/* UN_048 - primitive type new initialize */
int UN_048_function1(int& value, int* value2) {
  return value + *value2;
}

void UN_048_function2() {
  int* x = new int(); // x initialize 0.
  int* y = new int; // y don't initialize.

  int ret = 0;
  ret += *x; //It's ok.
  ret += UN_048_function1(*x, y); //@violation UNINIT

  delete x;
  delete y;
}
