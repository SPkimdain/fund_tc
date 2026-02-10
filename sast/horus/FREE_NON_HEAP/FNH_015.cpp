
/* FNH_015 - complex flow */
void FNH_015_function(int flag, int flag2, int* src) {
  int value = 10;
  int* ptr = src;
  int x = 0;

  if(flag > 10) {
    if(flag2 == 0) {
      x++;
    }
    else {
      ptr = &value;
    }
  }
  
  if(flag2 != 0) {
    delete ptr; //@violation FREE_NON_HEAP
  }
}

