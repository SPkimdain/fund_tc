
/* SN_003 - simple case */

int SN_003_function1(int x) {
  return x - 10;
}

void SN_003_function2() {
  unsigned int p = 10;
  int y = 6;
  y = SN_003_function1(y);
  p = p << y; //@violation SHIFT_NEGATIVE  
}
