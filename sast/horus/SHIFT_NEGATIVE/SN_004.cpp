
/* SN_004 - Negative boundary */

int SN_004_function1(int bound) {
  if(bound < 0 && bound > -5) {
    return bound;
  }

  return 4;
}

void SN_004_function2(int x) {
  unsigned int p = 10;

  int offset = 0;
  offset = SN_004_function1(x);

  p = p << offset; //@violation SHIFT_NEGATIVE  
}
