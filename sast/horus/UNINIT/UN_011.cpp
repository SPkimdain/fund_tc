#pragma warning(disable : 4700)

/* UN_011 - Complex call expression */
int UN_011_function1(int value, int p) {
  if(value > 10) {
    return p;
  }
  else {
    return 0;
  }
}

void UN_011_function2() {
  int value = 10;
  int value2;

  int ret = 0;

  ret = (UN_011_function1(1, value2)) + // @violation UNINIT
    (UN_011_function1(20, value));

  value2 = 0;

  ret = (UN_011_function1(1, value)) + // Ok.
    (UN_011_function1(20, value)) + 
    (UN_011_function1(30, value2)); 
}
