
/* DBZ_004 - if branch2 */
void DBZ_004_function(int arg) {
  int value = 10;
  int value2 = 0;
  int* ptr1 = 0;
  if(arg == 10) {
    ptr1 = &value;
  }
  else {
    ptr1 = &value2;
  }

  int ret = 1000 / *ptr1; //@violation DIV_BY_ZERO
}
