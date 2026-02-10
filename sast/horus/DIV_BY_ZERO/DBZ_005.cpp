
/* DBZ_005 - switch branch  */
void DBZ_005_function(int arg) {
  int value = 10;
  switch(arg) {
  case 0:
  case 1:
  case 2:
    break;
  case 3:
    value = 0;
    break;
  default:
    break;
  }

  int ret = 1000 / value; //@violation DIV_BY_ZERO
}
