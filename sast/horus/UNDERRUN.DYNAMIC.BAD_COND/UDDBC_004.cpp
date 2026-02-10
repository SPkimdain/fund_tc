
/* UDDBC_004 - Check boundary value. */
void UDDBC_004_function(int idx) {
  int* buf = new int[10];
  if(buf == 0) {
    return;
  }

  if(idx < 1) {
    // [min, 0]
    buf[idx] = 10; //It's ok. 
  }

  if(idx >= -1) {
    // [-1, max]
    buf[idx] = 15; //@violation UNDERRUN.DYNAMIC.BAD_COND
  }

  delete[] buf;
}
