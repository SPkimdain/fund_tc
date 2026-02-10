
/* DZMC_014 - trace return values */
int DZMC_014_function1(int flag) {
  auto&& DZMC_014_lambda = [](int f) {
    if(f > 100) {
      return 1;
    }
    else {
      return 0;
    }
  };

  return DZMC_014_lambda(flag);
}

int DZMC_014_function2(int flag, int value) {
  int ret = DZMC_014_function1(flag);
  if(ret == 1) {
    return value;
  }
  else{
    return 0;
  }
}

int DZMC_014_function3(int value) {  
  int ret = 0;

  if(value != 0) {
    ret++;
  }

  ret += DZMC_014_function2(101, value);

  return 2000 / value; //@violation DIV_BY_ZERO.MISSING_CHECK
}

