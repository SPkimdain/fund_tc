
/* OD_016 - Shift operator value */
void OD_016_function() {
  int value = 1;
  int* p = new int[5];
  if(p == 0) {
    return;
  }
  int* ptr = p;
  int ret = 0;

  value = value << 2; // 4
  value = value >> 1; // 2

  ptr = p + 6;

  //Impossible path.
  ret = *ptr; //@violation OVERRUN.DYNAMIC
  delete[] p;
}
