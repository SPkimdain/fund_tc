

/* DBZ_038 - path test from opus */
void DBZ_038_function1(int x, int y) {
  int result = 10;
  const int zero = 0;
  if(x > 100) {
    if(y < 20) {
      result = result / zero; //@violation DIV_BY_ZERO
    }
  }
}

