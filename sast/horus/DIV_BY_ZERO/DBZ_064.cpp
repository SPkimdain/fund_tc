
/* DBZ_064 - lambda case1. */
void DBZ_064_function() {
  int x = 10;

  auto&& DBZ_064_lambda = [x](int val) {
    return x - val;
  };

  int p = 10000;

  int ret = DBZ_064_lambda(11);
  p = p / ret; //It's ok.

  int ret2 = DBZ_064_lambda(10);
  p = p / ret2; //@violation DIV_BY_ZERO
}
