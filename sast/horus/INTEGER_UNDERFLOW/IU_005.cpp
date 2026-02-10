
/* IU_005 intended underflow */
void IU_005_function() {
  int si1 = -2147483647;
  int si2 = 2;
  int t = -520;
  unsigned short vio = (unsigned short)(int)(t); // no violation
  int result = si1 - si2; //@violation INTEGER_UNDERFLOW
}
