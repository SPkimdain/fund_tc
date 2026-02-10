
/* SEB_006 - Over boundary3 */

int SU_006_function1(int bound) {
  if(bound > 7 && bound <= 8) {
    return bound;
  }

  return 4;
}

void SEB_006_function2(int x) {
  unsigned char p = 10;

  int offset = 0;
  offset = SU_006_function1(x);

  p = p << offset; //@violation SHIFT_EXCEEDS_BIT_WIDTH  
}
