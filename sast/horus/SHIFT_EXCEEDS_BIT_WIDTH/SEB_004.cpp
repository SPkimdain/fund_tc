
/* SEB_004 - Over boundary */

int SU_004_function1(int bound) {
  if(bound > 8 && bound < 10) {
    return bound;
  }

  return 4;
}

void SEB_004_function2(int x) {
  unsigned char p = 10;

  int offset = 0;
  offset = SU_004_function1(x);

  p = p << offset; //@violation SHIFT_EXCEEDS_BIT_WIDTH  
}
