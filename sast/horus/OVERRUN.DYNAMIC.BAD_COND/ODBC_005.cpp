
/* ODBC_005 - switch branch  */
void ODBC_005_function(int arg, unsigned int index) {
  int* value = new int[4];
  if(value == 0) {
    return;
  }

  int* ptr = 0;
  if(index < 6) { //Wrong check.
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
    *ptr = 10; //@violation OVERRUN.DYNAMIC.BAD_COND
  }

  delete[] value;
}
