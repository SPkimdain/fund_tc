
/* OD_013 - for2 */
void OD_013_function(int value, int value2) {
  int p = 100;
  int* ptr = new int[3];
  if(ptr == 0) {
    return;
  }
  int ret = 0;

  for(int i = 0; i < 2; i++) {
    if(value > 10) { // True or False
      if(value2 > 5) { // True or False
        ret += ptr[4]; //@violation OVERRUN.DYNAMIC
      }
    }
  }
  
  delete[] ptr;
}
