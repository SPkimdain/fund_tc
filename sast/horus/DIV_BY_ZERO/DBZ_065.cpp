
/* DBZ_065 - lambda case2. */
void DBZ_065_function() {
  int x = 10;

  auto&& DBZ_065_lambda = [&x](int val) {
    return x - val;
  };

  int p = 100;
  
  int ret1 = p / DBZ_065_lambda(5); //It's ok.

  x = 5;

  int op2 = DBZ_065_lambda(5);

  int ret2 = p / op2; //@violation DIV_BY_ZERO
}
