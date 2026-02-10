
/* ODBC_004 - Check boundary value. */
void ODBC_004_function(int idx) {
  int* buf = new int[10];
  if(buf == 0) {
    return;
  }

  if(idx < 1) {
    // [min, 0]
    buf[idx] = 10; //It's ok. 
  }

  if(idx <= 10) {
    // [min, 10]
    buf[idx] = 15; //@violation OVERRUN.DYNAMIC.BAD_COND
  }

  delete[] buf;
}
