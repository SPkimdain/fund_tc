
/* UDS_016 - Shift operator value */
void UDS_016_function() {
  int value = 1;
  int p[5] = { 0, };
  int* ptr = p;
  int ret = 0;

  value = value << 2; // 4
  value = value >> 1; // 2

  ptr = p - 1;

  //Impossible path.
  ret = *ptr; //@violation UNDERRUN.STATIC
}
