
/* UDSBC_001 - Simple case. */
void UDSBC_001_function(int idx) {
  int buf[10];

  if(idx >= -1 && idx < 10) {
    buf[idx] = 10;             //@violation UNDERRUN.STATIC.BAD_COND
  }
}
