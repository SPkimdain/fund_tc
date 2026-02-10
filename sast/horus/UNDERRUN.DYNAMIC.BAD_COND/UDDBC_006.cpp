
/* UDDBC_006 - if branch */
void UDDBC_006_function(int arg, int index) {
  int* value = new int[4];
  if(value == 0) {
    return;
  }

  int* ptr = 0;

  if(index >= -2) { //[-2, max]
    if(arg == 10) {
      ptr = (value + 1);
    }
    else {
      ptr = (value + index);
    }

    *ptr = 10; //@violation UNDERRUN.DYNAMIC.BAD_COND
  }

  delete[] value;
}
