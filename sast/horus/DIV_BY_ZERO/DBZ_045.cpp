
/* DBZ_045 - % operator */
void DBZ_045_function() {
  int p = 100;
  int x = p % 10; // 0;

  int ret = 1000 / x; //@violation DIV_BY_ZERO
}
