/* Check upper bound. */

void OSBC_003_function(int idx) {
  int buf[10] = { 0, };

  if(idx >= 9) {
    // [9, max]
    buf[idx] = 10; //It's ok. 
  }

  if(idx >= 1 && idx < 12) {
    // [1, 11]
    buf[idx] = 15; //@violation OVERRUN.STATIC.BAD_COND

    buf[idx] = 20; //Ignore. second bad cond.

    buf[idx] = 30; //Ignore. third bad cond.
  }
}
