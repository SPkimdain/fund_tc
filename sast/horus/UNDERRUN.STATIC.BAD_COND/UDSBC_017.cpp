
/* UDSBC_017 - complex constraint range */
static const int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

int UDSBC_017_function1(int idx) {
  int fileno = 0;
  fileno = (idx / 2) - 2;
  
  if(fileno < 0 || fileno > 9) {
    return 0;
  }
  
  int ret = arr[fileno];
  
  return ret;
}

void UDSBC_017_function2(int idx) {
  int ret = 0;
  
  if(idx >= 2 && idx <= 4) {
    ret = UDSBC_017_function1(idx); //It's ok.
  }
  
  int buf[10];

 if(idx >= -1 && idx < 10) {
   buf[idx] = 10;             //@violation UNDERRUN.STATIC.BAD_COND
 }
  
  ret++;
}

