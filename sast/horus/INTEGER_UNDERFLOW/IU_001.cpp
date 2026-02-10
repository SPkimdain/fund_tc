
/* IU_001 simple underflow */
void IU_001_function() {
  int si1 = -2147483647;
  int si2 = 2;
  int result = si1 - si2; //@violation INTEGER_UNDERFLOW
}
