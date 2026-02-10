/* Check lower bound. */

void UDSBC_003_function(int idx) {
  int buf[10] = { 0, };

  if(idx >= 9) {
    // [9, max]
    buf[idx] = 10; //It's ok. 
  }

  if(idx >= -10 && idx < 10) {
    // [-10, 9]
    buf[idx] = 15; //@violation UNDERRUN.STATIC.BAD_COND

    buf[idx] = 20; //Ignore. second bad cond.

    buf[idx] = 30; //Ignore. third bad cond.
  }
}
