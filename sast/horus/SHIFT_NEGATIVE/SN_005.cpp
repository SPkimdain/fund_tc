
/* SN_005 - Negative boundary2 */

int SN_005_function1(int bound) {
  if(bound < 1 && bound > -5) {
    return bound - 3;
  }

  return 4;
}

void SN_005_function2(int x) {
  unsigned int p = 10;

  int offset = 0;
  offset = SN_005_function1(x);

  p = p << offset; //@violation SHIFT_NEGATIVE  
}
