
/* OV_016 - Shift operator value */
void OV_016_function() {
  int value = 1;
  int p[5] = { 0, };
  int* ptr = p;
  int ret = 0;

  value = value << 2; // 4
  value = value >> 1; // 2

  ptr = p + 6;

  //Impossible path.
  ret = *ptr; //@violation OVERRUN.STATIC
}
