
/* DZMC_009 - Function call, deep depth */

bool DZMC_009_function1(bool flag, int value) {
  if(flag == false) {
    int ret = 500 / value; // DIV_BY_ZERO
    return true;
  }
  return false;
}


bool DZMC_009_function2(int value) {
  return DZMC_009_function1(false, value);
}

void DZMC_009_function3(bool flag, int data1, int data2) {
  if(flag == true) {
    DZMC_009_function2(data1);
  }
  else{
    DZMC_009_function2(data2);
  }
}

int DZMC_009_function4(int data1, int data2) {
  int actValue = 20;
  if(data1 != 0) {
    data1 = actValue;
  }
  if(data2 != 0) {
    data1 = 20;
  }

  DZMC_009_function3(false, data1, data2); //@violation DIV_BY_ZERO.MISSING_CHECK

  return 0;
}


