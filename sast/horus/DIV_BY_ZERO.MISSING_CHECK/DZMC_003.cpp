
/* DZMC_003 - if branch1 */
void DZMC_003_function(int arg, int value2) {
  int value = 10;
  int* ptr = 0;
  int ret = 0;
  if(value2 != 0) {
    ret++;
  }


  if(arg == 10) {
    ptr = &value;
    ret = 1000 / *ptr;
  }
  else {
    ptr = &value2;
    ret = 1000 / *ptr; //@violation DIV_BY_ZERO.MISSING_CHECK
  }

}
