/* Check upper bound. */
#include <stdlib.h>

void ODBC_003_function(int idx) {
  int* buf = (int*)malloc(10 * sizeof(int));
  if(buf == 0) {
    return;
  }

  if(idx >= 9) {
    // [9, max]
    buf[idx] = 10; //It's ok. 
  }

  if(idx >= 6 && idx < 12) {
    // [6, 11]
    buf[idx] = 15; //@violation OVERRUN.DYNAMIC.BAD_COND

    buf[idx] = 20; //Ignore. second bad cond.

    buf[idx] = 30; //Ignore. third bad cond.
  }

  free(buf);
}
