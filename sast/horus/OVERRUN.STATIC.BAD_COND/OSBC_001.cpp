
/* OSBC_001 - Simple case. */
void OSBC_001_function(int idx) {
  int buf[10];

  if(idx >= 0 && idx <= 10) {
    buf[idx] = 10;             //@violation OVERRUN.STATIC.BAD_COND
  }
}
