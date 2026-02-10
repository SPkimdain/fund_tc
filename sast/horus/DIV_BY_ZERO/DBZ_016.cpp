
/* DBZ_016 - Shift operator value */
void DBZ_016_function() {
  int value = 1;
  int p = 10;
  int ret = 0;

  value = value << 2; // 4
  value = value >> 1; // 2

  ret = 100 / (p - 10); //@violation DIV_BY_ZERO

}
