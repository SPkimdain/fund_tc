
/* ODBC_018 - reminder */

void ODBC_018_function1(int attr) {
  char* hex = new char[15]();
  if(attr >= 22 && attr <= 31) { /* [22, 31] [33, 34] */
    attr = attr % 15; /* [0, 1], [7, 14] */
    hex[attr] = 'x'; //It's ok.
  }
  
  delete[] hex;
}


void ODBC_018_function2(int idx) {
  int* buf = new int[10]();

  if(idx >= 0 && idx <= 10) {
    buf[idx] = 10;             //@violation OVERRUN.DYNAMIC.BAD_COND
  }
  
  delete[] buf;
}
