
/* DZMC_005 - switch branch  */
void DZMC_005_function(int arg, int value) {
  switch(arg) {
  case 0:
  case 1:
  case 2:
    break;
  case 3:
    if(value != 0) {
      arg++;
    }
    break;
  default:
    break;
  }

  int ret = 1000 / value; //@violation DIV_BY_ZERO.MISSING_CHECK
}
