
/* UN_016 - Shift operator value */
void UN_016_function() {
  int value = 1;
  int p;
  int* ptr = &p;
  int ret = 0;

  value = value << 2; // 4
  value = value >> 1; // 2

  ptr = 0;
 
  ret = p; //@violation UNINIT
}
