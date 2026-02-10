
/* NMO_001 - simple case */
void NMO_001_function() {
  int x = -10;
  int y = 5;
  
  int z = y % x; //@violation NEGATIVE_MOD_OPERATION
}
