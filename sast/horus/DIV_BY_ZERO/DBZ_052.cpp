
/* DBZ_052 - trace return values */
int DBZ_052_function1(int flag) {
  if(flag > 100) {
    return 1;
  }
  else{
    return 0;
  }
}

int DBZ_052_function2(int flag, int value) {
  int ret = DBZ_052_function1(flag);
  if(ret == 1) {
    return value;
  }
  else{
    return 0;
  }
}

int DBZ_052_function3() {
  int value = 5;
  int ret = 0;
  
  ret = DBZ_052_function2(101, value); // 5

  return ret / (ret - 5); //@violation DIV_BY_ZERO
}

