
/* SEB_005 - Over boundary2 */

int SU_005_function1(int bound) {
  if(bound > 5 && bound < 8) {
    return bound + 3;
  }

  return 4;
}

void SEB_005_function2(int x) {
  unsigned char p = 10;

  int offset = 0;
  offset = SU_005_function1(x);

  p = p << offset; //@violation SHIFT_EXCEEDS_BIT_WIDTH
}
