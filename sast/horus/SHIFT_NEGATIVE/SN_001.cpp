
/* SN_001 - simple case */

void SN_001_function() {
  unsigned int p = 10;
  p = p << -2; //@violation SHIFT_NEGATIVE  
}
