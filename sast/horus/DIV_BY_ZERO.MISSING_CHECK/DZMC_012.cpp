

/* DZMC_012 - path test from opus */
void DZMC_012_function1(int x, int y, int zero) {
  int result = 10;
  bool check = true;
  if(zero != 0) {
    check = false;
  }

  if(x > 100) {
    if(y < 20) {
      result = result / zero; //@violation DIV_BY_ZERO.MISSING_CHECK
    }
  }
}

