
/* ODBC_001 - Simple case. */
void ODBC_001_function(int idx) {  
  int* buf = new int[10];
  if(buf == 0) {
    return;
  }

  if(idx >= 0 && idx <= 10) {
    buf[idx] = 10;             //@violation OVERRUN.DYNAMIC.BAD_COND
  }

  delete[] buf;
}
