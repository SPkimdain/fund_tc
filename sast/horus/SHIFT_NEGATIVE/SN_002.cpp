
/* SN_002 - simple case2 */

void SN_002_function() {
  unsigned int p = 10;
  int x = -5;
  p = p << x; //@violation SHIFT_NEGATIVE  

}
