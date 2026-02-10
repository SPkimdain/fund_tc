
/* NMO_003 - simple case with lambda. */
void NMO_003_function() {
  auto&& NMO_003_lambda = [](int flag) {
    if(flag > 10) {
      return -5;
    }
    else {
      return 5;
    }
  };

  int x = -10;
  int y = 5;

  int ret1 = y % NMO_003_lambda(3); //It's ok.

  int ret2 = y % NMO_003_lambda(11); //@violation NEGATIVE_MOD_OPERATION
}
