
/* UDSBC_006 - if branch */
void UDSBC_006_function(int arg, int index) {
  int value[4] = { 0, };
  int* ptr = 0;

  if(index >= -1) { //[-1, max]
    if(arg == 10) {
      ptr = (value + 1);
    }
    else {
      ptr = (value + index);
    }

    *ptr = 10; //@violation UNDERRUN.STATIC.BAD_COND
  }
}
