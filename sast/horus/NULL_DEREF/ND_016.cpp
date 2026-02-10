
/* ND_016 - Shift operator value */
void ND_016_function() {
  int value = 1;
  int p = 10;
  int* ptr = &p;
  int ret = 0;

  value = value << 2; // 4
  value = value >> 1; // 2

  ptr = 0;

  ret = *ptr; //@violation NULL_DEREF

}
