
/* DZMC_002 - prev function call */

int DZMC_002_function1(int valuex) {
  
  if(valuex == 0) {
    return 1;
  }
  else {
    return 2;
  }
}


void DZMC_002_function2(int value) {
  int p = 100;  

  DZMC_002_function1(value);

  int k = 5000 / value; //@violation DIV_BY_ZERO.MISSING_CHECK  
  
}
