
/* ODBC_006 - if branch */
void ODBC_006_function(int arg, int index) {
  int* value = new int[4];
  if(value == 0) {
    return;
  }

  int* ptr = 0;

  if(index > 0 && index < 10) { //Wrong check.
    if(arg == 10) {
      ptr = (value + 1);
    }
    else {
      ptr = (value + index);
    }

    *ptr = 10; //@violation OVERRUN.DYNAMIC.BAD_COND
  }

  delete[] value;
}
