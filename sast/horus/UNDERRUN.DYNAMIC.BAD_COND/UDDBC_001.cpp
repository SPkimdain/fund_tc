
/* UDDBC_001 - Simple case. */
void UDDBC_001_function(int idx) {  
  int* buf = new int[10];
  if(buf == 0) {
    return;
  }

  if(idx >= -1 && idx < 10) {
    buf[idx] = 10;             //@violation UNDERRUN.DYNAMIC.BAD_COND
  }

  delete[] buf;
}
