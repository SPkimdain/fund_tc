/* CAV_031 - lambda return */

void CAV_031_function(int flag) {
  auto&& CAV_031_lambda = [](int x) {
    return x - 10;
  };

  int a;
  unsigned int b;
  a = -20;
  if(flag > 1) {
    b = a - CAV_031_lambda(20);  //@violation CAST_ALTERS_VALUE.EXT
  }
  else {
    b = a + CAV_031_lambda(40); //It's ok. b = -20 + 30.
  }
}
