
/* DZMC_004 - if branch2 */
void DZMC_004_function(int arg, int value, int value2) {
  value = 10;
  int ret = 0;

  if(value2 != 0) {
    ret++;
  }
  
  int* ptr1 = 0;
  if(arg == 10) {
    ptr1 = &value;
  }
  else {
    ptr1 = &value2;
  }

  int ret2 = 1000 / *ptr1; //@violation DIV_BY_ZERO.MISSING_CHECK
}
