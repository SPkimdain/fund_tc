
/* DBZ_003 - if branch1 */
void DBZ_003_function(int arg) {
  int value = 10;
  int value2 = 0;
  int* ptr = 0;
  int ret = 0;
  if(arg == 10) {
    ptr = &value;
    ret = 1000 / *ptr;
  }
  else {
    ptr = &value2;
    ret = 1000 / *ptr; //@violation DIV_BY_ZERO
  }
  
}
