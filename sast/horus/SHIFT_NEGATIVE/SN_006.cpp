
/* SN_006 - Negative boundary3 */

int SN_006_function1(int bound) {
  if(bound < 0 && bound >= -1) {
    return bound;
  }

  return 4;
}

void SN_006_function2(int x) {
  unsigned int p = 10;

  int offset = 0;
  offset = SN_006_function1(x);

  p = p << offset; //@violation SHIFT_NEGATIVE  
}
