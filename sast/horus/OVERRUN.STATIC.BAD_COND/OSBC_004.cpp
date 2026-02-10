/* OSBC_004 - Check boundary value. */
void OSBC_004_function(int idx) {
  int buf[10];

  if(idx < 1) {
    // [min, 0]
    buf[idx] = 10; //It's ok. 
  }

  if(idx <= 10) {
    // [min, 10]
    buf[idx] = 15; //@violation OVERRUN.STATIC.BAD_COND
  }
}
