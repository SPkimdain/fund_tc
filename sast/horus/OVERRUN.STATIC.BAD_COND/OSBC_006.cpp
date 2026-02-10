
/* OSBC_006 - if branch */
void OSBC_006_function(int arg, int index) {
  int value[4] = { 0, };
  int* ptr = 0;

  if(index > 0 && index < 10) { //Wrong check.
    if(arg == 10) {
      ptr = (value + 1);
    }
    else {
      ptr = (value + index);
    }

    *ptr = 10; //@violation OVERRUN.STATIC.BAD_COND
  }
}
