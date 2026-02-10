
/* UDSBC_005 - switch branch  */
void UDSBC_005_function(int arg, int index) {
  int value[4] = { 0, };
  int* ptr = 0;
  if(index >= -3) { //Wrong check.
    switch(arg) {
    case 0:
    case 1:
    case 2:
      ptr = (value + 1);
      break;
    case 3:
      ptr = (value + index);
      break;
    default:
      ptr = value;
      break;
    }
    *ptr = 10; //@violation UNDERRUN.STATIC.BAD_COND
  }
}
