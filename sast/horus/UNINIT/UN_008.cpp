#pragma warning(disable : 4700)

/* UN_008 - Function call, return value */
int UN_008_function1(int arg, int flag) {
  if(flag > 10) {
    return arg;
  }
  else {
    return 0;
  }
}

void UN_008_function2() {
  int value;
  int ptr = 0;
  ptr = UN_008_function1(value, 15); //@violation UNINIT
  value = 0;
}
