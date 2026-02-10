/* UDSBC_004 - Check boundary value. */
void UDSBC_004_function(int idx) {
  int buf[10];

  if(idx < 1) {
    // [min, 0]
    buf[idx] = 10; //It's ok. 
  }

  if(idx >= -1) {
    // [-1, max]
    buf[idx] = 15; //@violation UNDERRUN.STATIC.BAD_COND
  }
}
