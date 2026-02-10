/* SEB_003 - simple case3 */

int SEB_003_function1(int x) {
  return x + 2;
}

void SEB_003_function2(unsigned char u8a, unsigned char u16a){
  unsigned char c1 = u8a << SEB_003_function1(2);
  
  unsigned char c2 = u8a << SEB_003_function1(6); //@violation SHIFT_EXCEEDS_BIT_WIDTH
}
