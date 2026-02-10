/* DBZ_013 - for2 */
void DBZ_013_function(int value, int value2) {
  int p = 100;
  int* ptr = &p;
  int ret = 0;

  for(int i = 0; i < 2; i++) {
    if(value > 10) { // True or False
      if(value2 > 5) { // True or False
        ret += 100 / (*ptr - 100); //@violation DIV_BY_ZERO
      }
    }
  }
}
